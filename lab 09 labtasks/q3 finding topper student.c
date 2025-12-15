#include <stdio.h>

float Topper(float avg[], int n);

int main() {
    int marks[5][3];
    float avg[5];
    char grade[5];
    int i, j;

    for (i = 0; i < 5; i++) {
        int sum = 0;
        printf("\nEnter marks for Student %d:\n", i + 1);
        for (j = 0; j < 3; j++) {
            printf(" Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);
            sum = sum + *(marks[i] + j);
        }
        avg[i] = sum / 3;

        if (avg[i] >= 85) {
            grade[i] = 'A';
        } else if (avg[i] >= 70) {
            grade[i] = 'B';
        } else if (avg[i] >= 55) {
            grade[i] = 'C';
        } else if (avg[i] >= 40) {
            grade[i] = 'D';
        } else {
            grade[i] = 'F';
        }
    }

    float (*TopperFunc)(float[], int) = Topper;

    printf("\n\nStudent Results\n");
    for (i = 0; i < 5; i++) {
        printf("Student %d Average: %.2f Grade: %c\n", i + 1, avg[i], grade[i]);
    }

    int topperIndex = topperFunc(avg, 5);
    printf("\nTopper is Student %d with Average: %.2f\n", topperIndex + 1, avg[topperIndex]);

    return 0;
}

float Topper(float avg[], int n) {
    int i, topper = 0;
    for (i = 1; i < n; i++) {
        if (*(avg + i) > *(avg + topper)) {
            topper = i;
        }
    }
    return topper;
}
