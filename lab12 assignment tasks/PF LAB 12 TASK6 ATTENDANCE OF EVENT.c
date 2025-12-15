#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int total_recursive(int *arr, int idx, int size) {
    if (idx == size) return 0;
    return arr[idx] + total_recursive(arr, idx + 1, size);
}

int main() {
    int n, extra, i;
    printf("Enter number of gates: ");
    scanf("%d", &n);

    int *gate_counts = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
        printf("Attendance for Gate %d: ", i + 1);
        scanf("%d", &gate_counts[i]);
    }

    printf("Add more gates? Enter 0 for none: ");
    scanf("%d", &extra);
    if (extra > 0) {
        gate_counts = (int *)realloc(gate_counts, (n + extra) * sizeof(int));
        for (i = n; i < n + extra; i++) {
            printf("Attendance for Gate %d: ", i + 1);
            scanf("%d", &gate_counts[i]);
        }
        n += extra;
    }

    int total = total_recursive(gate_counts, 0, n);
    int highest = gate_counts[0], gate_num = 1;
    for (i = 1; i < n; i++) {
        if (gate_counts[i] > highest) {
            highest = gate_counts[i];
            gate_num = i + 1;
        }
    }

    FILE *fp = fopen("attendance.txt", "w");
    time_t t;
    time(&t);
    char *timestamp = ctime(&t);

    fprintf(fp, "Event Attendance Report\nGenerated on: %s\n", timestamp);
    for (i = 0; i < n; i++)
        fprintf(fp, "Gate %d: %d attendees\n", i + 1, gate_counts[i]);
    fprintf(fp, "Total Attendees (recursive): %d\nGate with highest attendance: Gate %d (%d attendees)\n",
            total, gate_num, highest);
    fclose(fp);

    printf("\nAttendance saved to attendance.txt successfully.\n");
    free(gate_counts);
    return 0;
}

