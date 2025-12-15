#include <stdio.h>
int main() {
    int marks[2][3][3];
    int class, std, sub;
    int total_score = 0;
    int top_class_index, top_student_index;

    printf("\n Enter Scores: \n");
    for (class = 0; class < 2; class++) {
        for (std = 0; std < 3; std++) {
            printf("\n Enter Scores for Class %d, Student %d\n", class + 1, std + 1);
            for (sub = 0; sub < 3; sub++) {
                printf(" Subject %d Score: ", sub + 1);
                scanf("%d", &marks[class][std][sub]);
            }
        }
    }

    printf("\n Total Scores \n");
    for (class = 0; class < 2; class++) {
        for (std = 0; std < 3; std++) {
            int current_student_total = 0;
            for (sub = 0; sub < 3; sub++) {
                current_student_total += marks[class][std][sub];
            }

            printf("Class %d, Student %d Total Score: %d\n", class + 1, std + 1, current_student_total);

            if (current_student_total > total_score) {
                total_score = current_student_total;
                top_class_index = class;
                top_student_index = std;
            }
        }
    }

    printf("\n============================================\n");
    int score_class = marks[top_class_index][top_student_index][0];
    int score_student = marks[top_class_index][top_student_index][1];
    int score_c = marks[top_class_index][top_student_index][2];

    printf("Top Performer is: Class %d, Student %d\n", top_class_index + 1, top_student_index + 1);
    printf("Total Score: %d\n", total_score);
    printf("Scores (Class/Student/C): %d / %d / %d\n", score_class, score_student, score_c);
    printf("\n============================================\n");

    return 0;
}
