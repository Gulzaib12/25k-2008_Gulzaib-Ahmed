#include <stdio.h>

int main() {
    float rainfall_data[7];
    float average_rainfall = 0.0;
    int max_day_index = 0;

    for (int i = 0; i < 7; i++) {
        printf("Enter rainfall for Day %d (in mm): ", i + 1);
        scanf("%f", &rainfall_data[i]);
    }

    analyze_rainfall(rainfall_data, &average_rainfall, &max_day_index);

    printf("\n--- Analysis Results of Rainfall ---\n");
    printf("Average Rainfall over 7 days: %.2f mm\n", average_rainfall);
    printf("Maximum Rainfall Day: Day %d (%.2f mm)\n", max_day_index + 1, rainfall_data[max_day_index]);

    int above_average_count = 0;
    float *ptr = rainfall_data;
    printf("\n--- Week Summary ---\n");

    for (int i = 0; i < 7; i++) {
        if (*ptr > average_rainfall) {
            above_average_count++;
        }
        ptr++;
    }

    if (above_average_count >= 3) {
        printf("Rainy Week\n");
    } else {
        printf("Normal Week\n");
    }

    return 0;
}

float analyze_rainfall(float *data, float *avg, int *max_day_index) {
    float total = 0;
    float max_rainfall = -1.0;

    for (int i = 0; i < 7; i++) {
        total += data[i];
        if (data[i] > max_rainfall) {
            max_rainfall = data[i];
            *max_day_index = i;
        }
    }

    float calculated_average = total / 7;
    *avg = calculated_average;
    return max_rainfall;
}

