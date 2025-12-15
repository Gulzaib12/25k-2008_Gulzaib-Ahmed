#include <stdio.h>

int main() {
    int house_units[10];
    int bill[10];
    int flaged_houses = 0;
    int total_revenue = 0;
    int i;
    int count = 0;

    for (i = 0; i < 10; i++) {
        printf("Enter consumed units of house: %d\n", i + 1);
        scanf("%d", &house_units[i]);

        if (house_units[i] < 200) {
            bill[i] = 15 * house_units[i];
        } else if (house_units[i] >= 200 && house_units[i] < 500) {
            bill[i] = 20 * house_units[i];
        } else {
            bill[i] = 25 * house_units[i];
            if (house_units[i] >= 700) {
                count++;
            }
        }
        total_revenue = total_revenue + bill[i];
    }

    printf("----------------------------------------------------\n");
    printf("                  summary of electricity bill       \n");
    printf("----------------------------------------------------\n");

    for (i = 0; i < 10; i++) {
        printf("\tTotal bill for house: %d is %d\n", i + 1, bill[i]);
    }

    printf("\tTotal number of flaged houses are: %d\n", count);

    printf("\tTotal revenue is: %d\n", total_revenue);

    return 0;
}
