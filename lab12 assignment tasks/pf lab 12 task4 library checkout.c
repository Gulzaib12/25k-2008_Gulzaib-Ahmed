#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char title[100];
    char member[20];
    int hour_out;
    int due_days;
} log_entry;

int main() {
    int n, more, j;

    printf("enter initial checkout count: ");
    scanf("%d", &n);

    log_entry *data = (log_entry *)malloc(n * sizeof(log_entry));
    if (data == NULL) {
        printf("allocation error\n");
        return 1;
    }

    for (j = 0; j < n; j++) {
        printf("\n-- record %d --\n", j + 1);
        printf("book title: ");
        scanf(" %[^\n]", data[j].title);
        printf("member id: ");
        scanf("%s", data[j].member);
        printf("checkout hour (0-23): ");
        scanf("%d", &data[j].hour_out);
        printf("due days: ");
        scanf("%d", &data[j].due_days);
    }

    printf("\nadd more records? enter number (0 for none): ");
    scanf("%d", &more);

    if (more > 0) {
        data = (log_entry *)realloc(data, (n + more) * sizeof(log_entry));
        if (data == NULL) {
            printf("resize failed\n");
            return 1;
        }

        for (j = n; j < n + more; j++) {
            printf("\n-- record %d --\n", j + 1);
            printf("book title: ");
            scanf(" %[^\n]", data[j].title);
            printf("member id: ");
            scanf("%s", data[j].member);
            printf("checkout hour (0-23): ");
            scanf("%d", &data[j].hour_out);
            printf("due days: ");
            scanf("%d", &data[j].due_days);
        }

        n += more;
    }

    FILE *fp = fopen("checkout_logs.csv", "w");
    if (fp == NULL) {
        printf("file error\n");
        free(data);
        return 1;
    }

    fprintf(fp, "title,member,hour_out,due_days\n");
    for (j = 0; j < n; j++) {
        fprintf(fp, "%s,%s,%d,%d\n",
                data[j].title,
                data[j].member,
                data[j].hour_out,
                data[j].due_days);
    }

    fclose(fp);
    printf("\nlog saved to checkout_logs.csv\n");

    free(data);
    return 0;
}

