#include <stdio.h>

int main() {
    int base, exponent, i;
    int result = 1;
    printf("Enter value of base: ");
    scanf("%d", &base);
    printf("Enter value of exponent must be in positive: ");
    scanf("%d", &exponent);

    for(i=1; i<=exponent; i++) {
        result = result * base;
    }
    printf("%d raised to the exponent of %d is: %d\n", base, exponent, result);

    return 0;
}
