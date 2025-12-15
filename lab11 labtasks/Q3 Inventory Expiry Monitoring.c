#include <stdio.h>
#include <string.h>

typedef struct category {
    char category_name[30];
    char department[30];
} Category;

typedef struct Product {
    char product_name[50];
    int expiry_days;
    Category category;
} Product;

void display_product(Product p) {
    printf("Product: %s\n", p.product_name);
    printf("Category: %s %s\n", p.category.category_name, p.category.department);
    printf("Days Remaining: %d days\n", p.expiry_days);
}

void input_product(Product *p) {
    printf("Enter product name: ");
    fgets(p->product_name, sizeof(p->product_name), stdin);
    p->product_name[strcspn(p->product_name, "\n")] = 0;

    printf("Enter expiry days: ");
    scanf("%d", &p->expiry_days);
    getchar(); // Consume the newline character

    printf("Enter category name: ");
    fgets(p->category.category_name, sizeof(p->category.category_name), stdin);
    p->category.category_name[strcspn(p->category.category_name, "\n")] = 0;
}

void check_expiry_recursive(const Product inventory[], int index, int num_products, int alert_days) {
    if (index >= num_products) {
        return;
    }

    const Product current_product = inventory[index];
    if (current_product.expiry_days <= alert_days) {
        printf("\nALERT EXPIRING SOON\n");
        display_product(current_product);
    } else {
        printf("%s expires in %d days.\n", current_product.product_name, current_product.expiry_days);
    }

    check_expiry_recursive(inventory, index + 1, num_products, alert_days);
}

int main() {
    int num_products, alert_days_threshold, i;
    printf("Enter the number of products: ");
    scanf("%d", &num_products);
    getchar(); // Consume the newline character

    Product inventory[num_products];

    printf("Enter product details:\n");
    for (i = 0; i < num_products; i++) {
        printf("\nProduct %d:\n", i + 1);
        input_product(&inventory[i]);
    }

    printf("\nEnter the alert threshold (N days): ");
    scanf("%d", &alert_days_threshold);

    if (alert_days_threshold < 0) {
        printf("Error: The alert threshold cannot be negative.\n");
        return 1;
    }

    printf("\nExpiry Check Alert \n", alert_days_threshold);
    check_expiry_recursive(inventory, 0, num_products, alert_days_threshold);

    printf("\nExpiry Check Complete!\n");

    return 0;
}
