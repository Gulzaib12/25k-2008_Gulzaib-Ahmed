#include <stdio.h>
#include <string.h>

int main() {
    FILE *file;
    char cities[5][50];
    float temp[5];
    float max_temp;
    int max_index = 0;
    int i;

    file = fopen("temperature.txt", "w");
    for (i = 0; i < 5; i++) {
        printf("Enter the city name: ");
        scanf("%s", cities[i]);
        printf("Enter city average temperature: ");
        scanf("%f", &temp[i]);
        fprintf(file, "%s %.2f\n", cities[i], temp[i]);

        if (i == 0) {
            max_temp = temp[i];
        } else if (temp[i] > max_temp) {
            max_temp = temp[i];
            max_index = i;
        }
    }

    fclose(file);
    printf("\n highest temperature: %s (%.2f) \n", cities[max_index], max_temp);
    return 0;
}

