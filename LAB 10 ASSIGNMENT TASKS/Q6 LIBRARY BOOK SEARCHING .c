#include <stdio.h>
#include <string.h>

int main() {
    char books[10][50], title[50];
    int n = 10, found = 0;
    int i;
    char choice;

    for (i = 0; i < n; i++) {
        printf("Enter title for book: %d\n", i + 1);
        scanf("%s", books[i]);
    }

    do {
        printf("Enter book title to search: ");
        scanf("%s", title);

        found = 0;
        for (i = 0; i < n; i++) {
            if (strcmp(title, books[i]) == 0) {
                printf("Book Found\n");
                found = 1;
                break;
            }
        }

        if (!found)
            printf("Book Not Found\n");
        printf("Do you want to search for another book? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    return 0;
}

