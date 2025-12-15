#include <stdio.h>

struct File {
    char fileName[100];
    float originalSize;
    float reductionRate;
};

float estimateFileSize(struct File file, int k);

int main() {
    struct File file;
    int k; // number of compression rounds

    printf("Enter File Name: ");
    scanf("%s", file.fileName);
    printf("Enter Original File Size: ");
    scanf("%f", &file.originalSize);
    printf("Enter Reduction Rate: ");
    scanf("%f", &file.reductionRate);
    printf("Enter Number of Compression Rounds: ");
    scanf("%d", &k);

    float estimatedSize = estimateFileSize(file, k);
    printf("\nEstimated file size of '%s' after %d compression rounds: %.2f\n", file.fileName, k, estimatedSize);

    return 0;
}

float estimateFileSize(struct File file, int k) {
    if (k == 0) {
        return file.originalSize;
    } else {
        float previousSize = estimateFileSize(file, k - 1);
        float currentSize = previousSize - (previousSize * file.reductionRate);
        return currentSize;
    }
}


