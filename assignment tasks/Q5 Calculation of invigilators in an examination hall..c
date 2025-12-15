#include <stdio.h>
int main() {
    int std_in_section[6];
    int i;
    int total_invigilator = 0;
    int invigilator[6];
    int total_students = 0;
    int chief_invigilator = 0;
    int final_invigilator = 0;
    for (i = 0; i < 6; i++) {
        printf("Enter number of students in section: %d\n", i + 1);
        scanf("%d", &std_in_section[i]);

        if (std_in_section[i] < 30) {
            invigilator[i] = 1;
        } else if (std_in_section[i] >= 30 && std_in_section[i] <= 60) {
            invigilator[i] = 2;
        } else {
            invigilator[i] = 3;
        }

        total_invigilator = total_invigilator + invigilator[i];
        total_students = total_students + std_in_section[i];
    }

    if (total_students > 300) {
        chief_invigilator = 1;
    }

    final_invigilator = total_invigilator + chief_invigilator;

    for (i = 0; i < 6; i++) {
        printf("Number of students in section: %d are %d\n", i + 1, std_in_section[i]);
        printf("\nassign invigilator: %d\n", invigilator[i]);
    }

    printf("Total invigilators are needed: %d\n", final_invigilator);
    printf("Total students in 6 sections are: %d\n", total_students);

    return 0;
}
