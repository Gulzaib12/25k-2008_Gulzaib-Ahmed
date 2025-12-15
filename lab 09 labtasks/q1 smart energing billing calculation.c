#include <stdio.h>

int bill_calculation(int *arr, int *ptr);

int main() {
    int houses[10];
    int bill[10];
    int i, total;

    printf("Enter the energy consumption in kilo watts of 10 houses:\n");
    for (i = 0; i < 10; i++) {
        printf("House %d: ", i + 1);
        scanf("%d", &houses[i]);
    }

    total = bill_calculation(houses, bill);

    for (i = 0; i < 10; i++) {
        printf("House %d: consumed %d units the Bill is = Rs. %d\n", i + 1, houses[i], bill[i]);
    }

    printf("\nTotal Revenue Collected = Rs. %d\n", total);

    return 0;
}

int bill_calculation(int *arr, int *ptr) {
    int total = 0, i;

    for (i = 0; i < 10; i++) {
        if ((*(arr + i)) <= 100) {
            *(ptr + i) = (*(arr + i)) * 10; // Rs.10 per unit
        } else {
            *(ptr + i) = (100 * 10) + ((*(arr + i) - 100) * 15); // Rs.15/unit beyond 100
        }
        total = total + *(ptr + i);
    }

    return total;
}
