#include <stdio.h>
#include <string.h>

int main() {
    char email[50];
    printf("Enter email address: ");
    scanf("%s", email);

    char *symbol = strchr(email, '@');
    if (symbol != NULL) {
        char domain_name[50];
        strcpy(domain_name, symbol + 1);
        printf("Domain name: %s\n", domain_name);
    } else {
        printf("You entered Invalid email\n");
    }

    return 0;
}

