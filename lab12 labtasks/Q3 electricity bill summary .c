#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct UserElectricity_bill {
    char name[50];
    int* units;
    int days;
};

int totalUnits(int* units, int days) {
    int total = 0;
    int i;
    for (i = 0; i < days; i++) {
        total += units[i];
    }
    return total;
}

int calculateBill(int total) {
    if (total < 100)
        return total * 5;
    else if (total < 300)
        return total * 7;
    else
        return total * 10;
}

int main() {
    int userCount;
    int i, j;

    printf("Enter number of users: ");
    scanf("%d", &userCount);

    struct UserElectricity_bill* users = (struct UserElectricity_bill*)malloc(userCount * sizeof(struct UserElectricity_bill));

    for (i = 0; i < userCount; i++) {
        printf("\nEnter user name %d: ", i + 1);
        scanf("%s", users[i].name);

        printf("Enter number of days recorded for %s: ", users[i].name);
        scanf("%d", &users[i].days);

        users[i].units = (int*)malloc(users[i].days * sizeof(int));

        for (j = 0; j < users[i].days; j++) {
            printf("Enter units consumed on day %d: ", j + 1);
            scanf("%d", &users[i].units[j]);
        }

        int choice, additionalDays;
        printf("Do you want to add more days for %s? (1=Yes, 0=No): ", users[i].name);
        scanf("%d", &choice);

        if (choice == 1) {
            printf(" ");
            scanf("enter num of days to add %d", &additionalDays); // Error in image: scanf needs two arguments
            users[i].units = (int*)realloc(users[i].units, (users[i].days + additionalDays) * sizeof(int));
            
            for (j = users[i].days; j < users[i].days + additionalDays; j++) {
                 printf("Enter units consumed on day %d: ", j + 1);
                 scanf("%d", &users[i].units[j]);
            }
            users[i].days += additionalDays;
        }
    }

    FILE* f = fopen("electricity_bill_summary.txt", "w");
    if (f == NULL) {
        printf("Error \n");
        return 1;
    }

    printf("\n Bill Summary \n");
    fprintf(f, " Bill Summary \n");

    for (i = 0; i < userCount; i++) {
        int total = totalUnits(users[i].units, users[i].days);
        float average = (float)total / users[i].days;
        int bill = calculateBill(total);

        printf("\nUser: %s\n", users[i].name);
        printf("Total units consumed: %d\n", total);
        printf("Average daily consumption: %.2f\n", average);
        printf("Bill amount: %d\n", bill);

        fprintf(f, "\nUser: %s\n", users[i].name);
        fprintf(f, "Total units consumed: %d\n", total);
        fprintf(f, "Average daily consumption: %.2f\n", average);
        fprintf(f, "Bill amount: %d\n", bill);
    }

    fclose(f);
    printf("\nBill summary saved to electricity_bill_summary.txt\n");

    for (i = 0; i < userCount; i++)
        free(users[i].units);
    free(users);

    return 0;
}
