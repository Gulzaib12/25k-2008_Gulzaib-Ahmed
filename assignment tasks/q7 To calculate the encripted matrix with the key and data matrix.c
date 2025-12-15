#include <stdio.h>
int main() {
    int data_matrix[3][3];
    int key_matrix[3][3];
    int encrypted_matrix[3][3] = {0};
    int i, j, k;

    printf("\n Enter values for the 3x3 Data Matrix \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter Data [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &data_matrix[i][j]);
        }
    }

    printf("\n Enter values for the 3x3 Key Matrix \n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter Key [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &key_matrix[i][j]);
        }
    }

    // Matrix Multiplication (Data * Key)
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            for (k = 0; k < 3; k++) {
                encrypted_matrix[i][j] += data_matrix[i][k] * key_matrix[k][j];
            }
        }
    }

    printf("\n===============================\n");
    printf("Encrypted Matrix (Result of Data Matrix * Key matrix ):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d\t", encrypted_matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
