#include <stdio.h>
#include <stdlib.h>

struct OrderSystem {
    char itemName[50];
    int quantity;
    int unitPrice;
    char customerName[50];
};

int i;
int main() {
    int n;
    printf("Enter number of orders: ");
    scanf("%d", &n);
    
    struct OrderSystem* orders = (struct OrderSystem*)malloc(n * sizeof(struct OrderSystem));
    
    for (i = 0; i < n; i++) {
        printf("\nEnter item name for order %d: ", i + 1);
        scanf("%s", orders[i].itemName);
        
        printf("Enter quantity: ");
        scanf("%d", &orders[i].quantity);
        
        printf("Enter unit price: ");
        scanf("%d", &orders[i].unitPrice);
        
        printf("Enter customer name: ");
        scanf("%s", orders[i].customerName);
    }
    
    FILE* file = fopen("food order system.txt", "w");
    if (file == NULL) {
        printf("Error \n");
        return 1;
    }
    
    int totalRevenue = 0;
    for (i = 0; i < n; i++) {
        fprintf(file, "Item: %s\n", orders[i].itemName);
        fprintf(file, "Quantity: %d\n", orders[i].quantity);
        fprintf(file, "Unit Price: %.2f\n", (float)orders[i].unitPrice);
        fprintf(file, "Customer: %s\n", orders[i].customerName);
        
        totalRevenue += orders[i].quantity * orders[i].unitPrice;
    }
    
    printf("TOTAL REVENUE :%d", totalRevenue);
    fprintf(file, "Total Revenue: %d\n", totalRevenue);
    
    fclose(file);
    free(orders);
    
    printf("\nOrders saved to food order system.txt\n");
    
    return 0;
}
