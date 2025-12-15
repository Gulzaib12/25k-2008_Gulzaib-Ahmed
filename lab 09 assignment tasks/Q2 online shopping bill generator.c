#include <stdio.h>
float discounts(float *prices, float *total_after_discount);
int main() {
    int i;
    float product_prices[5];
    float total_amount_ptr = 0.0;
    
    for (i = 0; i < 5; i++) {
        printf("Enter price of product %d: ", i + 1);
        scanf("%f", &product_prices[i]);
    }
    
    discounts(product_prices, &total_amount_ptr); 
    
    printf("Total Amount after all discounts is: %.2f\n", total_amount_ptr); 
    
    return 0;
}

float discounts(float *prices, float *total_after_discount) {
    int i;
    float discount;
    float discounted_price;
    float total = 0.0;
    
    for (i = 0; i < 5; i++) {
        float price = *(prices + i);
        
        if (price < 1000.0) {
            discount = 0.10;
        } else if (price >= 1000.0 && price < 5000.0) {
            discount = 0.15;
        } else {
            discount = 0.25;
        }
        
        discounted_price = price * (1.0 - discount);
        total += discounted_price;
        
        printf("Product %d product price : %.1f discounted price : %.2f\n", i + 1, price, discount * 100, discounted_price);
    }
    
    *total_after_discount = total;
}

