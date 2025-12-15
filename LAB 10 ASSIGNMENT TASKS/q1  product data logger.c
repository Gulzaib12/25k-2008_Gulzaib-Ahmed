#include <stdio.h>

int main() {
    FILE *file;
    char product_name[50];
    float price;
    int quantity;
    char choice;

    do {
        file = fopen("products.txt", "a");
        if (file == NULL) {
            printf("Error opening file!\n");
            return 1;
        }

        printf("Enter product name: ");
        scanf("%s", product_name);
        printf("Enter product price: ");
        scanf("%f", &price);
        printf("Enter product quantity: ");
        scanf("%d", &quantity);

        fprintf(file, "%s %.2f %d\n", product_name, price, quantity);
        fclose(file);

        printf("Do you want to add another product? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Data stored successfully!\n");
    return 0;
}

