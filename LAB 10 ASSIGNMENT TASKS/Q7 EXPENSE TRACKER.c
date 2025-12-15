#include <stdio.h>

int main() {
    FILE *file;
    char category[50];
    float amount;
    char choice;

    do {
        file = fopen("expenses.txt", "a");
        printf("Enter expense category: ");
        scanf("%s", category);
        printf("Enter amount: ");
        scanf("%f", &amount);

        fprintf(file, "%s %.2f\n", category, amount);
        fclose(file);

        printf("Do you want to add another expense? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    file = fopen("expenses.txt", "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("\nExpenses:\n");
    while (fscanf(file, "%s %f", category, &amount) == 2) {
        printf("%s %.2f\n", category, amount);
    }
    
    fclose(file);

    return 0;
}

