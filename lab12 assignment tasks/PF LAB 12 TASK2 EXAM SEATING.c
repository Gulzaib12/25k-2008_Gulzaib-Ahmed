#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char nm[50];
    char rn[20];
    int sn;
} record;

int chk_alpha_num(char *s, int k) {
    if (s[k] == '\0') 
        return 1;
    if (!isalnum(s[k])) 
        return 0;
    return chk_alpha_num(s, k + 1);
}

void get_roll(char *r) {
    for (;;) {
        printf("enter roll (letters & digits only): ");
        scanf("%s", r);
        if (chk_alpha_num(r, 0)) 
            break;
        printf("invalid roll format.\n");
    }
}

int main() {
    record *arr = NULL;
    int n, add, p;

    printf("enter initial student count: ");
    scanf("%d", &n);
    getchar();

    arr = (record *)malloc(n * sizeof(record));
    if (arr == NULL) {
        printf("alloc error\n");
        return 1;
    }

    for (p = 0; p < n; p++) {
        printf("\n-- student %d --\n", p + 1);
        printf("enter name: ");
        while (getchar() != '\n');
        scanf("%[^\n]", arr[p].nm);

        get_roll(arr[p].rn);

        printf("enter seat: ");
        scanf("%d", &arr[p].sn);
    }

    printf("\nadd more? enter count (0 if none): ");
    scanf("%d", &add);

    if (add > 0) {
        arr = (record *)realloc(arr, (n + add) * sizeof(record));
        if (arr == NULL) {
            printf("resize error\n");
            return 1;
        }

        for (p = n; p < n + add; p++) {
            printf("\n-- student %d --\n", p + 1);
            printf("enter name: ");
            scanf(" %[^\n]", arr[p].nm);

            get_roll(arr[p].rn);

            printf("enter seat: ");
            scanf("%d", &arr[p].sn);
        }

        n += add;
    }

    FILE *fp = fopen("seating.txt", "w");
    if (fp == NULL) {
        printf("file open error\n");
        free(arr);
        return 1;
    }

    fprintf(fp, "exam seating sheet\n\n");
    for (p = 0; p < n; p++) {
        fprintf(fp, "student %d:\n", p + 1);
        fprintf(fp, "name: %s\n", arr[p].nm);
        fprintf(fp, "roll: %s\n", arr[p].rn);
        fprintf(fp, "seat: %d\n\n", arr[p].sn);
    }

    fclose(fp);
    printf("\nseating saved to seating.txt\n");

    free(arr);
    return 0;
}

