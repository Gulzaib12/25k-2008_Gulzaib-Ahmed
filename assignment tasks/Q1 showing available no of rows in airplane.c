#include <stdio.h>

int main() {
    int airline_seats[10][4] = {{0}};
    int choice = 1;
    int i, j;
    int row;
    int seat;
    int row_index;
    int seat_index;
    int full_rows = 0;
    int row_full;

    while (choice == 1) {
        printf("\nCurrent Seat Map (1=Reserved, 0=Available) \n");
        printf("\nRow:  Seat 1 Seat 2 Seat 3 Seat 4\n");

        for (i = 0; i < 10; i++) {
            printf("\n%d   ", i + 1);

            for (j = 0; j < 4; j++) {
                printf("  %d  ", airline_seats[i][j]);
            }
            printf("\n");
        }

        printf("\n-------------------------------------------------\n");

        printf("Enter Your Row Choice (1-10) for reservation: ");
        scanf("%d", &row);
        printf("Enter Your Seat Choice (1-4) for reservation: ");
        scanf("%d", &seat);

        row_index = row - 1;
        seat_index = seat - 1;

        if (row_index < 0 || row_index >= 10 || seat_index < 0 || seat_index >= 4) {
            printf("\n Enter valid choice\n");
        } else {
            if (airline_seats[row_index][seat_index] == 0) {
                airline_seats[row_index][seat_index] = 1;
                printf("\n Row %d, Seat %d is Reserved for you \n", row, seat);
            } else {
            	printf("\n Row %d, Seat %d is already Reserved \n", row, seat);
            }
        }

        printf("\n Enter 1 to make another reservation, or 0 for exit: ");
        scanf("%d", &choice);

    }

    for (i = 0; i < 10; i++) {
        row_full = 1;
        for (j = 0; j < 4; j++) {
            if (airline_seats[i][j] == 0) {
                row_full = 0;
                break;
            }
        }
        if (row_full == 1) {
            full_rows++;
        }
    }

    printf("Total number of full rows occupied: %d\n", full_rows);

    return 0;
}

