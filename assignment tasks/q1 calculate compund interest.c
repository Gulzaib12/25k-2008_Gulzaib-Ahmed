#include <stdio.h>
#include <math.h>

int main() {
    int year;
    int p_amount = 1000; //p_amount=principal amount
    float rate = 0.05;

    for(year=1;year<=10;year++) {
        float total_amount = p_amount * pow(1 + rate, year);
        printf("total amount is: %f at the end of year %d\n", total_amount, year);
    }

    return 0;
}
