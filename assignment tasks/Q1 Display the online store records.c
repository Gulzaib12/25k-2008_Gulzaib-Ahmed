#include <stdio.h>

int main(){

    int item_prices[10];
    float discounted_prices[10];
    int i;
    float total_amount = 0.0;

    for(i = 0; i < 10; i++){
        float discount;
        printf("Enter price of Product %d: ", i + 1);
        scanf("%d", &item_prices[i]);

        if(item_prices[i] < 1000){
            discount = item_prices[i] - (item_prices[i] * 0.05);
        }
        else if(item_prices[i] <= 5000){
            discount = item_prices[i] - (item_prices[i] * 0.10);
        }
        else{
            discount = item_prices[i] - (item_prices[i] * 0.15);
        }
        discounted_prices[i] = discount;
        total_amount = total_amount + discount;

        printf("Amount of Product %d after discount is %.2f\n", i + 1, discount);
    }
    printf("************* Bill *************\n");
    printf("Your Total Amount Of The 10 Items Is: %.2f\n", total_amount);

    if(total_amount > 25000.0){
        printf("You earn a GOLD VOUCHER\n");
    }
    else{
        printf("No any kind of voucher you earn.\n");
    }

    return 0;
}
