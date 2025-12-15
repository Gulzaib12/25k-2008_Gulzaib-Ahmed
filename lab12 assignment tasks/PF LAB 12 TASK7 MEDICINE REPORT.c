#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[50];
    int quantity;
    float price;
} medicine_item;

void save_inventory(medicine_item *list, int count) {
    FILE *fp = fopen("medicine_inventory.txt", "w");
    fprintf(fp, "Medicine Inventory\n\n");
    int i;
    for (i = 0; i < count; i++)
        fprintf(fp, "%d. %s - Qty: %d, Price: %.2f\n", i + 1, list[i].name, list[i].quantity, list[i].price);
    fclose(fp);
}

int main() {
    int n, choice;
    printf("Enter number of medicines initially: ");
    scanf("%d", &n);

    medicine_item *inventory = (medicine_item *)malloc(n * sizeof(medicine_item));
    int i;
	for (i = 0; i < n; i++) {
        printf("\nMedicine %d Name: ", i + 1);
        scanf(" %[^\n]", inventory[i].name);
        printf("Quantity: ");
        scanf("%d", &inventory[i].quantity);
        printf("Unit Price: ");
        scanf("%f", &inventory[i].price);
    }

    while (1) {
        printf("\n1.Add Medicine 2.Remove Medicine 3.Low Stock 4.Total Value 5.Save & Exit\nChoice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            n++;
            inventory = (medicine_item *)realloc(inventory, n * sizeof(medicine_item));
            printf("Medicine Name: ");
            scanf(" %[^\n]", inventory[n - 1].name);
            printf("Quantity: ");
            scanf("%d", &inventory[n - 1].quantity);
            printf("Price: ");
            scanf("%f", &inventory[n - 1].price);
        } else if (choice == 2) {
            if (n == 0) continue;
            int idx;
            printf("Enter medicine number to remove (1-%d): ", n);
            scanf("%d", &idx);
            int i;
            for ( i = idx - 1; i < n - 1; i++)
                inventory[i] = inventory[i + 1];
            n--;
            inventory = (medicine_item *)realloc(inventory, n * sizeof(medicine_item));
        } else if (choice == 3) {
        	int i;
            for (i = 0; i < n; i++)
                if (inventory[i].quantity < 5)
                    printf("%s - Qty: %d\n", inventory[i].name, inventory[i].quantity);
        } else if (choice == 4) {
            float total = 0;
            int i;
            for (i = 0; i < n; i++)
                total += inventory[i].quantity * inventory[i].price;
            printf("Total Inventory Value: %.2f\n", total);
        } else if (choice == 5) {
            save_inventory(inventory, n);
            break;
        }
    }

    free(inventory);
    return 0;
}

