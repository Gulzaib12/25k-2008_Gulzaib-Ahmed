#include <stdio.h>
#include <stdlib.h>

int main() {
    int h, extra, limit;
    int x;

    printf("Enter initial number of hours: ");
    scanf("%d", &h);

    int *data = (int *)malloc(h * sizeof(int));
    if (data == NULL) {
        printf("Memory error\n");
        return 1;
    }

    printf("\nEnter steps for each hour:\n");
    for (x = 0; x < h; x++) {
        printf("Hour %d: ", x + 1);
        scanf("%d", &data[x]);
    }

    printf("\nAdd more hours? Enter number (0 for none): ");
    scanf("%d", &extra);

    if (extra > 0) {
        data = (int *)realloc(data, (h + extra) * sizeof(int));
        if (data == NULL) {
            printf("Resize error\n");
            return 1;
        }

        printf("\nEnter steps for extra hours:\n");
        for (x = h; x < h + extra; x++) {
            printf("Hour %d: ", x + 1);
            scanf("%d", &data[x]);
        }

        h += extra;
    }

    int highest = data[0];
    int sum = 0;
    int above = 0;

    printf("\nEnter step threshold: ");
    scanf("%d", &limit);

    for (x = 0; x < h; x++) {
        int v = data[x];
        sum += v;
        if (v > highest) highest = v;
        if (v > limit) above++;
    }

    printf("\n=== Fitness Summary ===\n");
    printf("Total Hours: %d\n", h);
    printf("Total Steps: %d\n", sum);
    printf("Peak Hour Steps: %d\n", highest);
    printf("Hours Above %d: %d\n", limit, above);

    FILE *out = fopen("fitness_tracker.txt", "w");
    if (out == NULL) {
        printf("File error\n");
        return 1;
    }

    fprintf(out, "Fitness Report\n");
    fprintf(out, "Hours: %d\n", h);
    fprintf(out, "Step Log:\n");

    for (x = 0; x < h; x++) {
        fprintf(out, "Hour %d: %d\n", x + 1, data[x]);
    }

    fprintf(out, "Total: %d\n", sum);
    fprintf(out, "Max: %d\n", highest);
    fprintf(out, "Above %d: %d\n", limit, above);

    fclose(out);

    printf("\nSaved to fitness_tracker.txt\n");

    free(data);
    return 0;
}

