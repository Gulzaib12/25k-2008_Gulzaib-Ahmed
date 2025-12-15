#include <stdio.h>
#include <math.h>

struct Building {
    int ID;
    double initialHeight;
    double growthRate;
};

double calculateHeight(struct Building *b, int day);

int main() {
    struct Building b;
    int day;

    printf("Enter Building ID: ");
    scanf("%d", &b.ID);
    printf("Enter Initial Height: ");
    scanf("%lf", &b.initialHeight);
    printf("Enter Growth Rate in decimal (0.05 for 5%): ");
    scanf("%lf", &b.growthRate);
    printf("Enter Day: ");
    scanf("%d", &day);

    double height = calculateHeight(&b, day);
    printf("Height of building %d on day %d: %.2f\n", b.ID, day, height);

    return 0;
}

double calculateHeight(struct Building *b, int day) {
    if (day == 0) {
        return b->initialHeight;
    } else {
        double prevHeight = calculateHeight(b, day - 1);
        return prevHeight + floor(prevHeight * b->growthRate);
    }
}

