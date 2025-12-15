#include<stdio.h>
int main() {
    int original_matrix[5][5];
    int sharpened_image[5][5];
    int i, j;
    int sum_original = 0, sum_sharpened = 0;

    printf("Enter pixel values (0 to 255) for a 5x5 image:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("Pixel [%d][%d]: ", i, j);
            scanf("%d", &original_matrix[i][j]);

            // Clamping the input values to 0-255 range
            if(original_matrix[i][j] < 0) original_matrix[i][j] = 0;
            if(original_matrix[i][j] > 255) original_matrix[i][j] = 255;
        }
    }

    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            // Sharpening logic: doubling the intensity
            if((original_matrix[i][j] * 2) > 255) {
                sharpened_image[i][j] = 255; // Clamp to max intensity
            }
            else {
                sharpened_image[i][j] = original_matrix[i][j] * 2;
            }
            sum_original = sum_original + original_matrix[i][j];
            sum_sharpened = sum_sharpened + sharpened_image[i][j];
        }
    }

    printf("\nOriginal Image:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%4d ", original_matrix[i][j]);
        }
        printf("\n");
    }

    printf("\nSharpened Image:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            printf("%4d ", sharpened_image[i][j]);
        }
        printf("\n");
    }

    float avg_original = sum_original / 25.0;
    float avg_sharpened = sum_sharpened / 25.0;
    printf("\nAverage intensity (before): %.2f\n", avg_original);
    printf("Average intensity (after): %.2f\n", avg_sharpened);

    return 0;
}
