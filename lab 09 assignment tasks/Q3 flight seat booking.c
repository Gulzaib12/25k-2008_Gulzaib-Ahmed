#include <stdio.h>
int flights = 3;
int max_seats = 9;
int seat_book = 1;
int seat_availability = 0;

int seats(int seats[3][9], int capacities[3]);
int manage_booking(int seats[3][9], int capacities[3]);
int display_occupied(int seats[3][9], int capacities[3]);

int main() {
    int flight_capacities[3] = {5, 7, 9};
    int flight_seats[3][9];
    int choice;
    
    seats(flight_seats, flight_capacities);
    
    do {
        printf("Enter your choice: 1. SEAT STATUS, 2. Book/cancel seat, 3. occupied seat, 4. Exit: \n");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                display_occupied(flight_seats, flight_capacities);
                break;
            case 2:
                manage_booking(flight_seats, flight_capacities);
                break;
            case 3:
                display_occupied(flight_seats, flight_capacities);
                break;
            case 4:
                printf("System shutting down. Goodbye!\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (choice != 4);
    
    return 0;
}

int seats(int seats[3][9], int capacities[3]) {
    int f, s;
    for (f = 0; f < flights; f++) {
        for (s = 0; s < capacities[f]; s++) {
        	seats[f][s] = seat_availability;
}
printf("\n All seats are available.\n");

int manage_booking(int seats[3][9], int capacities[3]) {
    int flight_num, seat_num, new_status;

    printf("Enter Flight (1-3): %d flights):
    scanf("%d", &flight_num);
    // Corrected Validation Logic: Check if flight_num is outside the valid range [1, flights)
    if (flight_num < 1 || flight_num > 3) { // Assuming 3 is the total number of flights based on array size
        printf("Invalid Flight Number.\n");
        return;
    }

    int flight_index = flight_num - 1;
    int capacity = capacities[flight_index];

    printf("Flight %d has %d seats.\n", flight_num, capacity);
    printf("Enter Seat (1-%d): ", capacity);
    scanf("%d", &seat_num);
    if (seat_num < 1 || seat_num > capacity) {
        printf("Invalid Seat Number.\n");
        return;
    }

    int seat_index = seat_num - 1;

    printf("Enter Status (1 for BOOK, 0 for CANCEL): ");
    if (scanf("%d", &new_status) != 1 || (new_status != seat_book && new_status != seat_availability)) {
        printf("Invalid status code. Use 1 or 0.\n");
        return 0; // The function signature is 'int', so returning 0 here.
    }

    seats[flight_index][seat_index] = new_status;

    if (new_status == seat_book) {
        printf("Seat %d on Flight %d BOOKED.\n", seat_num, flight_num);
    } else {
        printf("Seat %d on Flight %d CANCELLED.\n", seat_num, flight_num);
    }
}

int display_occupied(int seats[3][9], int capacities[3]) {
    int f, s;
    int occupied_count;

    for (f = 0; f < 3; f++) { // Assuming 3 is the number of flights
        occupied_count = 0;

        for (s = 0; s < capacities[f]; s++) {
            if (seats[f][s] == seat_book) {
                occupied_count++;
            }
        }
        printf("Flight %d (Capacity: %d): %d seats occupied.\n", f + 1, capacities[f], occupied_count);
    }
    return 0;
}
