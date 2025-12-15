#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int duration;
    float rate;
    float amount;
} RentalInfo;

int main() {
    int entries, extra, idx;

    printf("Enter number of initial rentals: ");
    scanf("%d", &entries);

    RentalInfo *records = (RentalInfo *)malloc(entries * sizeof(RentalInfo));
    if (records == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    for (idx = 0; idx < entries; idx++) {
        printf("\n--- Rental %d ---\n", idx + 1);

        printf("Enter rental duration (hours/days): ");
        scanf("%d", &records[idx].duration);

        printf("Enter cost per unit (per hour/day): ");
        scanf("%f", &records[idx].rate);

        records[idx].amount = records[idx].duration * records[idx].rate;
    }

    printf("\nDo you want to add more rentals? Enter number (0 for none): ");
    scanf("%d", &extra);

    if (extra > 0) {
        records = (RentalInfo *)realloc(records, (entries + extra) * sizeof(RentalInfo));
        if (records == NULL) {
            printf("Memory reallocation failed!\n");
            return 1;
        }

        for (idx = entries; idx < entries + extra; idx++) {
            printf("\n--- Rental %d ---\n", idx + 1);

            printf("Enter rental duration (hours/days): ");
            scanf("%d", &records[idx].duration);

            printf("Enter cost per unit (per hour/day): ");
            scanf("%f", &records[idx].rate);

            records[idx].amount = records[idx].duration * records[idx].rate;
        }

        entries += extra;
    }

    int total_duration = 0;
    int max_duration = records[0].duration;

    for (idx = 0; idx < entries; idx++) {
        total_duration += records[idx].duration;

        if (records[idx].duration > max_duration)
            max_duration = records[idx].duration;
    }

    FILE *fp = fopen("Rental_Invoices.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        free(records);
        return 1;
    }

    fprintf(fp, "-------- Car Rental Invoices --------\n\n");

    for (idx = 0; idx < entries; idx++) {
        fprintf(fp, "Customer %d:\n", idx + 1);
        fprintf(fp, "Rental Duration: %d (hours/days)\n", records[idx].duration);
        fprintf(fp, "Cost per Unit: %.2f\n", records[idx].rate);
        fprintf(fp, "Total Cost: %.2f\n\n", records[idx].amount);
    }

    fprintf(fp, "---------------------------------------\n");
    fprintf(fp, "Total Rental Time for the Day: %d\n", total_duration);
    fprintf(fp, "Highest Rental Duration: %d\n", max_duration);

    fclose(fp);

    printf("\nInvoices saved to Rental_Invoices.txt successfully.\n");

    free(records);
    return 0;
}

