#include <stdio.h>
int main () {
    int age, account_balance, ride_type, rides_request;
    float distance, surge_multiplier, basefare, total_fare;
    int loyaltyPoints;
    float discountPercentage = 0;
    int driver_rating;
    float driverDistance;

    // Passenger eligibility
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter account balance: ");
    scanf("%d", &account_balance);
    if (age > 18 && account_balance >= 200) {
        printf("Eligible for ride\n");
    } else {
        printf("Not eligible for ride\n");
        return 0;
    }

    // Ride type
    printf("Enter ride type (1 = Economy, 2 = Business, 3 = Luxury): ");
    scanf("%d", &ride_type);

    // Surge multiplier
    printf("Enter number of rides requested in area: ");
    scanf("%d", &rides_request);
    if (rides_request <= 2) {
        surge_multiplier = 1;
    } else if (rides_request <= 3) {
        surge_multiplier = 2;
    } else {
        surge_multiplier = 3;
    }
    printf("Surge multiplier: %.0f\n", surge_multiplier);
}
// Base fare calculation
printf("Enter distance (Km): ");
scanf("%f", &distance);
if (ride_type == 1) basefare = distance * 50;
else if (ride_type == 2) basefare = distance * 100;
else basefare = distance * 200;
total_fare = basefare * surge_multiplier;

// Discount
printf("Enter loyalty points: ");
scanf("%d", &loyaltyPoints);
if (loyaltyPoints > 1000) {
    discountPercentage = (loyaltyPoints > 1000) ? 20 : 5;
    total_fare = total_fare - total_fare * (discountPercentage / 100);
}

// Driver assignment
printf("Give rating to driver (1-5): ");
scanf("%d", &driver_rating);
printf("Enter driver distance from passanger (in Km): ");
scanf("%d", &distance);

if (driver_rating>=4 && distance<=5){
    printf("Top driver nearby");
}
else if (driver_rating>=3 && distance<=10){
    printf("Average driver assigned");
}
else{
    printf("No suitable driver available");
}

// Ride summary
printf("\nRide Summary:\n");
printf("Passenger eligibility: Eligible\n");
printf("Driver assigned with above considerations\n");
printf("Final fare after surge and discount: %.2f\n", total_fare);

return 0;
}
