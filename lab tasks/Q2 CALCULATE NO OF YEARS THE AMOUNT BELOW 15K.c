#include <stdio.h>

int main () {
    int amount = 30000;
    int year = 1;
    for(amount;amount>15000;amount = amount*0.9){
        printf("amount in year is: %d in the year %d\n", amount,year);
        year = year+1;
    }
    printf("TOTAL NUMBER OF YEARS IN WHICH AMOUNT DROP BELOW $15000 : %d\n", year);
    return 0;
}
