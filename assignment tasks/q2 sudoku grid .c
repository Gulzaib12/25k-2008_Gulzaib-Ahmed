#include <stdio.h>

int main() {
    int sudoku[3][3];
    int valid = 1;
    int i, j;
    int digit;

    printf("\n Enter the 9 digits for the 3x3 Sudoku grid (Enter 0 for empty cell):\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("Enter digit for Row %d, Column %d: ", i + 1, j + 1);
            scanf("%d", &sudoku[i][j]);
        }
    }

    printf("\n--- Input Grid ---\n");
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }

    printf("------------------\n");

    for (i = 0; i < 3; i++) {
        int duplicate[10] = {0};
        for (j = 0; j < 3; j++) {
            digit = sudoku[i][j];

            if (digit >= 1 && digit <= 9) {

                if (duplicate[digit] == 1) {
                    valid = 0;
                    printf("Duplicate digit %d found in Row %d.\n", digit, i + 1);
                    break;
                }
                duplicate[digit] = 1;
            }
        }
        if (valid == 0) {
            break;
        }
    }
    }
    
    if (valid == 1) {
        for (j = 0; j < 3; j++) {
            int duplicate[10] = {0};
            for (i = 0; i < 3; i++) {
                digit = sudoku[i][j];

                if (digit >= 1 && digit <= 9) {

                    if (duplicate[digit] == 1) {
                        valid = 0;
                        printf("Duplicate digit %d found in Column %d.\n", digit, j + 1);
                        break;
                    }
                    duplicate[digit] = 1;
                }
            }
            
            if (valid == 0) {
                break;
            }
        }
    }
    
    if (valid == 1) {
        int duplicate[10] = {0};
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                digit = sudoku[i][j];

                if (digit >= 1 && digit <= 9) {

                    if (duplicate[digit] == 1) {
                        valid = 0;
                        printf("Duplicate digit %d found in the entire 3x3 box.\n", digit);
                        break;
                    }
                    duplicate[digit] = 1;
                }
            }
            if (valid == 0) {
                break;
            }
        }
    }
    
    if (valid == 1) {
        printf("The 3x3 Sudoku Grid is VALID.\n");
    } else {
        printf("The 3x3 Sudoku Grid is INVALID.\n");
    }

    return 0;
}
