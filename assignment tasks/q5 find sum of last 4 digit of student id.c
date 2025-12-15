#include <stdio.h>

int main() {
    int digit1, digit2, digit3, digit4, sum;
    printf("Enter your student ID last 4 digits one by one:\n");
    printf("Enter 4th last digit: ");
    scanf("%d", &digit1);
    printf("Enter 3rd last digit: ");
    scanf("%d", &digit2);
    printf("Enter 2nd last digit: ");
    scanf("%d", &digit3);
    printf("Enter first last digit: ");
    scanf("%d", &digit4);

    sum = digit1 + digit2 + digit3 + digit4;

    printf("The sum of last 4 digits of your student id is: %d (%d+%d+%d+%d)\n", sum, digit1, digit2, digit3, digit4);

    return 0;
}
