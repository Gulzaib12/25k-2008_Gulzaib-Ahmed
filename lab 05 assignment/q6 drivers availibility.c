#include <stdio.h>
int main()
{
    int driver_rating, distance;

    printf("Give rating to driver (1-5): ");
    scanf("%d", &driver_rating);
    printf("Enter driver distance from passanger (in Km): ");
    scanf("%d", &distance);

    if (driver_rating >= 4 && distance <= 5)
    {
        printf("Top driver nearby");
    }
    else if (driver_rating >= 3 && distance <= 10)
    {
        printf("Average driver assigned");
    }
    else
    {
        printf("No suitable driver available");
    }
    return 0;
}
