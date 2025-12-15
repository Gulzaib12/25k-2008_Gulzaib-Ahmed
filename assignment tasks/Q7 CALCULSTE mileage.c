#include <stdio.h>
int main() {
    int vehicals_mileage[8];
    int i;
    int count = 0;
    for (i = 0; i < 8; i++) {
        printf("Enter milega for vehical: %d ", i + 1);
        scanf("%d", &vehicals_mileage[i]);
    }

    printf("----------Summary-------------------\n");

    for (i = 0; i < 8; i++) {
        if (vehicals_mileage[i] > 18) {
            printf("Vehical: %d Catogary is Efficient\n", i + 1);
        } else if (vehicals_mileage[i] >= 12 && vehicals_mileage[i] <= 17) {
            printf("Vehical: %d Catogary is Average\n", i + 1);
        } else {
            printf("Vehaical: %d Needs Maintenance\n", i + 1);
            count++;
        }
    }

    if (count > 3) {
        printf("----------ALERT-------------------\n");
        printf("\nFLEET EFFICIENCY ALERT!\n");
    }

    return 0;
}
