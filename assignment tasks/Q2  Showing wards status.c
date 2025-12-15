#include <stdio.h>

int main() {
    int wardsOccupancy[7];
    int i;
    int total_patients = 0;

    for(i=0; i<7; i++) {
        printf("Enter number of patients admitted in ward: %d\n", i+1);
        scanf("%d", &wardsOccupancy[i]);
    }

    for(i=0; i<7; i++) {
        if(wardsOccupancy[i] > 10) {
            printf("Ward: %d is overcrowded\n", i+1);
            printf("Ward: %d needs administrative review\n", i+1);
        }
        else if(wardsOccupancy[i] >= 6 && wardsOccupancy[i] <= 10) {
            printf("Ward: %d is stable\n", i+1);
        }
        else {
            printf("Ward: %d is underutilized\n", i+1);
            printf("Ward: %d needs administrative review\n", i+1);
        }
    }

    total_patients = total_patients + wardsOccupancy[i];

    printf("The total patients in the hospital are: %d\n", total_patients);

    return 0;
}
