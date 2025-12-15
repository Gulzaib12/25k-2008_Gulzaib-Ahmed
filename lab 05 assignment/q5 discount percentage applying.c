#include <stdio.h>
int main(){
    int points;
    float discount=0;
    printf("Enter loyalty points of a passanger: ");
    scanf("%d", &points);
    discount=(points>1000)?0.20:0.05;
    printf("Your Final Discount Percentage Is: %f", discount);
    return 0;
}
