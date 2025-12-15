#include <stdio.h>
#include <string.h>

int i,j;

int main() {
    char names[10][50];
    printf("Enter 10 student names:\n");
    for (i = 0; i < 10; i++) {
        printf("Student %d: ", i + 1);
        fgets(names[i], sizeof(names[i]), stdin);
    }
    
    for (i = 0; i < 10; i++) {
        for (j = i + 1; j < 10; j++) {
            if (strcmp(names[i], names[j]) > 0) {
                char students_name_length[50];
                strcpy(students_name_length, names[i]);
                strcpy(names[i], names[j]);
                strcpy(names[j], students_name_length);
            }
        }
    }

    for (i = 0; i < 10; i++) {
        printf("%s\n", names[i]);
    }
    
    return 0;
}

