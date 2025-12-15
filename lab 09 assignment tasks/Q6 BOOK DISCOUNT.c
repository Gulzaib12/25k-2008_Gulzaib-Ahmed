#include <stdio.h>

void calculate_value(float *prices, int *stocks, float *total_values, int count);
void apply_discount(int index, int *stocks, float *total_values, float *discounted_values);
int books = 5;

int main() {
    float prices[5];
    int stocks[5];
    float total_values[5];
    float discounted_values[5];

    printf("Please enter the information for the %d books:\n", books);
    for (int i = 0; i < books; i++) {
        printf("\nBook %d (i + 1):\n", i + 1);
        printf("Enter price of book: ");
        scanf("%f", &prices[i]);
        printf("Enter number of copies in stock: ");
        scanf("%d", &stocks[i]);
    }

    printf("\nProcessing books... Initial values, total values, books\n");
    calculate_value(prices, stocks, total_values, books);

    void (*discount_policy_ptr)(int, int *, float *, float *) = apply_discount;

    for (int i = 0; i < books; i++) {
        discount_policy_ptr(i, stocks, total_values, discounted_values);
    }

    printf("\nFINAL BOOK VALUATION REPORT\n");
    printf("%-5s %-10s %-15s %-15s\n", "Book", "Stock", "Initial Value", "Discounted Value");
    float total_library_value = 0.0;

    for (int i = 0; i < books; i++) {
        printf("%-5d %-10d %-15.2f %-15.2f\n", i + 1, stocks[i], total_values[i], discounted_values[i]);
        total_library_value += discounted_values[i];
    }

    printf("\nTOTAL LIBRARY VALUE AFTER DISCOUNTS: %.2f\n", total_library_value);

    return 0;
}

void calculate_value(float *prices, int *stocks, float *total_values, int count) {
    for (int i = 0; i < count; i++) {
        total_values[i] = prices[i] * stocks[i];
    }
}

void apply_discount(int index, int *stocks, float *total_values, float *discounted_values) {
    float discount_rate = 0.0;
    const int threshold_10 = 5;
    const int threshold_20 = 5;
    if (stocks[index] < threshold_10) {
        discount_rate = 0.0;
        printf("Book %d (Stock %d): No discount applied (0%%).\n", index + 1, stocks[index]);
    } else if (stocks[index] < threshold_20) {
        discount_rate = 0.10;
        printf("Book %d (Stock %d): 10%% discount applied.\n", index + 1, stocks[index]);
    } else {
        discount_rate = 0.20;
        printf("Book %d (Stock %d): 20%% discount applied.\n", index + 1, stocks[index]);
    }

    discounted_values[index] = total_values[index] * (1.0 - discount_rate);
}

