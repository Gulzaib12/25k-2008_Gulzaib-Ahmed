#include <stdio.h>
int main() {
    int greenhouse_temp[3][3][3];
    float layer_averages[3];
    int i, j, k;
    int max_temp_value = 0;
    int max_i, max_j, max_k;

    printf("\n Enter Temperature Readings \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                printf("Enter Temperature for Layer %d, %d, %d ", i + 1, j + 1, k + 1);
                scanf("%d", &greenhouse_temp[i][j][k]);
                if (greenhouse_temp[i][j][k] > max_temp_value) {
                    max_temp_value = greenhouse_temp[i][j][k];
                    max_i = i;
                    max_j = j;
                    max_k = k;
                }
            }
        }
    }

    int hottest_layer_index = 0;
    float highest_average = 0.0;
    
    printf("\n Layer Average Temperatures \n");
    for (i = 0; i < 3; i++) {
        int layer_sum = 0;
        
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                layer_sum += greenhouse_temp[i][j][k];
            }
        }
        
        layer_averages[i] = layer_sum / 9.0;
        printf("Layer %d Average: %.2f\n", i + 1, layer_averages[i]);
        
        if (layer_averages[i] > highest_average) {
            highest_average = layer_averages[i];
            hottest_layer_index = i;
        }
    }
    
    printf("\n============================\n");
    printf("The Hottest Layer is Layer %d with an average temperature of %.2f.\n",
           hottest_layer_index + 1, highest_average);
    printf("Maximum Temperature Found: %d\n", max_temp_value);
    printf("Coordinates of Max Temp: [Layer %d][Row %d][Column %d]\n",
           max_i + 1, max_j + 1, max_k + 1);
    printf("============================\n");

    return 0;
}
