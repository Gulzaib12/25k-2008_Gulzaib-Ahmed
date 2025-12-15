#include <stdio.h>
#include <math.h>
int main()
{
    int rides_request, distance;
    float surge_multiplier;
    int ride_type;
    float fare = 0;
    float Total_fare;
    printf("Enter your distance (km): ");
    scanf("%d", &distance);
    printf("Enter your rides request in an area: ");
    scanf("%d", &rides_request);
    printf("Enter your rides type: (1 = Economy, 2 = Business, 3 = Luxury)");
    scanf("%d", &ride_type);

    switch (ride_type)
    {
        case 1:
            fare = 50;
            break;
        case 2:
            fare = 100;
            break;
        case 3:
            fare = 200;
            break;
        default:
            printf("Enter valid input");
    }

    surge_multiplier = sqrt(rides_request) / 2;
    Total_fare = distance * fare + surge_multiplier;
    printf("Total fare is: %.2f", Total_fare);

    return 0;
}
