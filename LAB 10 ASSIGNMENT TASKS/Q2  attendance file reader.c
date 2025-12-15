#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char student[50];
    int count = 0;
    int choice;

    while (1) {
        printf("Enter your choice: (1. Add students to attendance record 2. Display attendance record 3. Exit) \n");
        scanf("%d", &choice);

        if (choice == 1) {
            file = fopen("attendance.txt", "a");
            if (file == NULL) {
                printf("Error opening file.\n");
                continue;
            }

            printf("Enter student names (type 'done' to finish):\n");
            while (1) {
                printf("ADD Student name: ");
                scanf("%s", student);

                if (strcmp(student, "done") == 0) {
                    break;
                }
                fprintf(file, "%s\n", student);
            }
            fclose(file);
        } else if (choice == 2) {
            file = fopen("attendance.txt", "r");
            if (file == NULL) {
                printf("Error opening file.\n");
                continue;
            }

            printf("\nAttendance Record:\n");
            count = 0;
            int result;

            while (1) {
                result = fscanf(file, "%s", student);
                if (result != 1) {
                    break;
                }
                printf("%s\n", student);
                count++;
            }

            fclose(file);
            printf("\nTotal students: %d\n", count);
        } else if (choice == 3) {
            break;
        } else {
            printf("enter correct choice \n");
        }
    }
    return 0;
}

