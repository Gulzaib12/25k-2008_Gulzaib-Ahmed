#include <stdio.h>

int main() {
    int count = 0;
    int num = 2;
    //my id is 25k-2008

    int idsecond_digit = 2; //due to undefine form i am taking it as 2
    int idlast_digit = 8;

    printf("The first 10 positive integers that are divisible by both 2nd and last digit of my Student ID, %d and %d:\n", idsecond_digit, idlast_digit);

    while (count < 10) {
        if (num % idsecond_digit == 0 && num % idlast_digit == 0) {
            printf("%d ", num);
            count++;
        }
        num++;
    }

    printf("\n");
    return 0;
}
