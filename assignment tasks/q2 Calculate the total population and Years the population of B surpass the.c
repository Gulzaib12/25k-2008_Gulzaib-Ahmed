#include <stdio.h>

int main() {
    int population_a = 10000;
    int population_b = 8000;
    int year = 0;

    while(population_b <= population_a) {
        population_a = population_a + 250;
        population_b = population_b + 400;
        year++;
    }

    printf("After %d Years the population of B surpass the population of A \n", year);
    printf("POPULATION OF TOWN A IS %d\n", population_a);
    printf("POPULATION OF TOWN B IS %d \n", population_b);

    return 0;
}
