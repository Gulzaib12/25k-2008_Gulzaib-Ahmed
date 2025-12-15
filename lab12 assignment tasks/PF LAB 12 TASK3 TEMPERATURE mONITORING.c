#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, extra, k;
    float limit;
    float hi, lo;
    int cnt = 0;

    printf("enter initial reading count: ");
    scanf("%d", &n);

    float *arr = (float *)malloc(n * sizeof(float));
    if (arr == NULL) {
        printf("alloc failed\n");
        return 1;
    }

    printf("\nenter all readings:\n");
    for (k = 0; k < n; k++) {
        printf("reading %d: ", k + 1);
        scanf("%f", &arr[k]);
    }

    printf("\nmore readings? enter number (0 for none): ");
    scanf("%d", &extra);

    if (extra > 0) {
        arr = (float *)realloc(arr, (n + extra) * sizeof(float));
        if (arr == NULL) {
            printf("resize failed\n");
            return 1;
        }

        printf("\nenter added readings:\n");
        for (k = n; k < n + extra; k++) {
            printf("reading %d: ", k + 1);
            scanf("%f", &arr[k]);
        }

        n += extra;
    }

    printf("\nset alert limit: ");
    scanf("%f", &limit);

    hi = arr[0];
    lo = arr[0];
    cnt = 0;

    for (k = 0; k < n; k++) {
        if (arr[k] > hi) hi = arr[k];
        if (arr[k] < lo) lo = arr[k];
        if (arr[k] > limit) cnt++;
    }

    FILE *fp = fopen("temperature_summary.txt", "w");
    if (fp == NULL) {
        printf("file error\n");
        free(arr);
        return 1;
    }

    fprintf(fp, "temperature report\n");
    fprintf(fp, "------------------\n");
    fprintf(fp, "total entries: %d\n", n);
    fprintf(fp, "max value: %.2f\n", hi);
    fprintf(fp, "min value: %.2f\n", lo);
    fprintf(fp, "limit: %.2f\n", limit);
    fprintf(fp, "above limit: %d\n", cnt);

    fclose(fp);
    printf("\nsaved to temperature_summary.txt\n");

    free(arr);
    return 0;
}

