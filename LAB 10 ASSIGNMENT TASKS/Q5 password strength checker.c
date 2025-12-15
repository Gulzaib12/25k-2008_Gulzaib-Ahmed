#include <stdio.h>
#include <string.h>

int main() {
    char password[50];
    int length, special = 0;
    int i;
    printf("Enter password: ");
    scanf("%s", password);

    length = strlen(password);
    for (i = 0; i < length; i++) {
        if (password[i] == '@' || password[i] == '#' || password[i] == '$' || password[i] == '%') {
            special = 1;
            break;
        }
    }

    if (length < 6)
        printf("Weak\n");
    else if (length >= 8 && special)
        printf("Strong\n");
    else
        printf("Medium\n");

    return 0;
}

