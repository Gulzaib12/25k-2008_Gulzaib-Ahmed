#include <stdio.h>

int main() {
    int student_fee_status[15];
    int delay_months[15];
    int fine[15];
    int i;
    int total_fine = 0;

    for (i = 0; i < 15; i++) {
        printf("Student: %d\n", i + 1);
        printf("Enter your fee payment status: (0 for unpaid & 1 for paid): \n");
        scanf("%d", &student_fee_status[i]);

        switch (student_fee_status[i]) {
            case 0:
                printf("Enter number of unpaid fee months: \n");
                scanf("%d", &delay_months[i]);
                if (delay_months[i] == 1) {
                    fine[i] = 500;
                } else {
                    fine[i] = 1000;
                }
                break;
            case 1:
                delay_months[i] = 0;
                fine[i] = 0;
                break;
            default:
                printf("Enter valid input");
        }
        total_fine = total_fine + fine[i];
    }

    printf("\n\n");
    printf("Student\tFee Status\tDelayed(Months)\tFine\tRemarks\n");
    printf("-------\t----------\t---------------\t----\t-------\n");

    for (i = 0; i < 15; i++) {
        printf("%d\t", i + 1);
        printf("%d\t\t", student_fee_status[i]);
        printf("%d\t\t", delay_months[i]);
        printf("%d\t", fine[i]);

        if (student_fee_status[i] == 1) {
            printf("Cleared\n");
        } else {
            printf("Defaulter\n");
        }
    }

    printf("\n\n");
    printf("TOTAL FINE COLLECTED: %d ", total_fine);

    return 0;
}
