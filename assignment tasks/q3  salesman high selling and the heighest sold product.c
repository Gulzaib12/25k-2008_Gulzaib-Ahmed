#include <stdio.h>

int main() {
    int sales_data[4][5];
    int salesman[4] = {0};
    int product[5] = {0};
    int i, j;

    for (i = 0; i < 4; i++) {
        printf("\n\tEnter sales data of Salesman %d:\n", i + 1);
        for (j = 0; j < 5; j++) {
            printf("\tProduct %d: ", j + 1);
            scanf("%d", &sales_data[i][j]);
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            salesman[i] = salesman[i] + sales_data[i][j];
        }
    }

    for (j = 0; j < 5; j++) {
        for (i = 0; i < 4; i++) {
            product[j] = product[j] + sales_data[i][j];
        }
    }

    int max_Product = product[0];
    int max_Product_index = 0;
    for (j = 1; j < 5; j++) {
        if (product[j] > max_Product) {
            max_Product = product[j];
            max_Product_index = j;
        }
    }

    int best_Salesman;
    int max_Sale = sales_data[0][max_Product_index];
    for (i = 1; i < 4; i++) {
        if (sales_data[i][max_Product_index] > max_Sale) {
            max_Sale = sales_data[i][max_Product_index];
            best_Salesman = i;
        }
    }

    for (i = 0; i < 4; i++) {
        if (salesman[i] > 10000) {
            salesman[i] += salesman[i] * 0.10;
        }
    }
}
}
    printf("\n=============================\n");
    printf("Total Sales of per salesman:\n");
    for (i = 0; i < 4; i++) {
        printf("Salesman %d made sell of Rs: %d\n", i + 1, salesman[i]);
    }
    printf("\nTotal sales per product:\n");
    for (j = 0; j < 5; j++) {
        printf("Product %d made sell of Rs: %d\n", j + 1, product[j]);
    }
    printf("\nMost expensive product is product %d (Rs. %d total)\n", max_Product_index + 1, max_Product);
    printf("Salesman who sold it on the highest price %d ( sold Rs. %d)\n", best_Salesman + 1, max_Sale);

    return 0;
}
