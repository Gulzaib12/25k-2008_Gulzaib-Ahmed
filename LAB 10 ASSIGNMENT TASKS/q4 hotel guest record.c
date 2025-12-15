#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char guests[100][50];
    char name[50];
    int room[100], total_records = 0, found = 0;
    int i;

    file = fopen("hotel.txt", "a+");
    
    printf("Enter number of records:");
    scanf("%d", &total_records);
    for (i = 0; i < total_records; i++) {
        printf("Enter the Guest name: ");
        scanf("%s", guests[i]);
        printf("Enter the Room number: ");
        scanf("%d", &room[i]);
        fprintf(file, "%s %d\n", guests[i], room[i]);
    }

    fclose(file);
    
    printf("Enter guest name to search: ");
    scanf("%s", name);
    file = fopen("hotel.txt", "r");
    
    while (fscanf(file, "%s %d", guests[total_records], &room[total_records]) != EOF) {
        if (strcmp(name, guests[total_records]) == 0) {
            printf("Room number: %d\n", room[total_records]);
            found = 1;
        }
        total_records++;
    }
    
    fclose(file);
    return 0;
}

