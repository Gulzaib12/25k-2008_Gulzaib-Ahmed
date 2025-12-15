#include <stdio.h>
#include <string.h>

int main() {
    char feedback[100];
    printf("Enter custumer feedback message: ");
    fgets(feedback, sizeof(feedback), stdin);
    feedback[strcspn(feedback, "\n")] = 0;

    int length = strlen(feedback);
    printf("Total characters: %d\n", length);

    if (strstr(feedback, "bad") != NULL) {
        printf("Found 'bad'\n");
    }

    if (strstr(feedback, "good") != NULL) {
        printf("Found 'good'\n");
    }

    char *pos;
    while ((pos = strstr(feedback, "bad")) != NULL) {
        strcpy(pos, "not good");
    }

    printf("Updated review: %s\n", feedback);
    return 0;
}

