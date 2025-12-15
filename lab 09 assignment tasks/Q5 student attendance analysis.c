#include <stdio.h>

int students = 30;
int days = 5;

int process_attendance(int (*attendance_array)[days], int num_students, int total_days);

int main() {
    int student_attendance[30][5];

    printf("--- Students Attendance---\n");
    printf("Enter attendance (1 for Present, 0 for Absent) for %d students over %d days.\n", students, days);

    for (int i = 0; i < students; i++) {
        printf("\nStudent: %d\n", i + 1);
        for (int j = 0; j < days; j++) {
            int attendance;
            do {
                printf(" Day %d attendance (0/1): ", j + 1);
                scanf("%d", &attendance);

                if (attendance != 1 && attendance != 0) {
                    printf("\nInvalid value. Please enter only 1 or 0.\n");
                }
            } while (attendance != 0 && attendance != 1);
            student_attendance[i][j] = attendance;
        }
    }

    printf("\n\n--- Processing Attendance Data ---\n");
    process_attendance(student_attendance, students, days);

    return 0;
}

int process_attendance(int (*attendance_array)[days], int num_students, int total_days) {
    int default_threshold = 75;
    int defaulter_count = 0;

    printf("\nINDIVIDUAL STUDENT REPORT\n");

    for (int i = 0; i < num_students; i++) {
        int days_present = 0;

        for (int j = 0; j < total_days; j++) {
            days_present += attendance_array[i][j];
        }

        float percentage = (float)days_present * 100.0 / total_days;

        char *status;
        if (percentage >= 90.0) {
            status = "Good";
        } else if (percentage >= default_threshold) {
            status = "Average";
        } else {
            status = "Poor (Defaulter)";
            defaulter_count++;
        }

        printf("Student %d: Present = %d/%d, attendance = %.2f%%, Status: %s\n", i + 1, days_present, total_days, percentage, status);
    }

    printf("\n--- FINAL SUMMARY ---\n");
    printf("Defaulter Threshold: Less than %d%%\n", default_threshold);
    printf("Total number of defaulters found: %d\n", defaulter_count);

    return defaulter_count;
}

