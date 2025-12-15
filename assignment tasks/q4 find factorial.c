#include <stdio.h>

int main() {
    int sum;
    int factorial = 1;
    int i = 1;
    printf("Enter the sum of your last two digits of your student ID: ");
    scanf("%d", &sum);

    for(i=1; i<=sum; i++) {
        factorial = factorial * i;
    }
    printf("Factorial of %d is %d\n", sum, factorial);

    return 0;
}
