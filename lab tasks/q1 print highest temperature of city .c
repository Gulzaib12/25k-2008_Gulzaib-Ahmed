#include<stdio.h>

int main(){
    float weather_temp[5][7];
    float avg[5];
    int i,j;
    printf("Enter the temperature of 5 city in (Celcius) for 7 days: \n");

    for(i=0; i<5; i++){
        printf("\nCity %d\n", i+1);
        for(j=0; j<7; j++){
            printf("Day %d: ", j+1);
            scanf("%f", &weather_temp[i][j]);
        }
    }

    printf("\n\nThe Entered Temperature of cities in 7 days: \n");
    for(i=0; i < 5; i++) {
        printf("City %d: ", i + 1);
        for(j=0; j < 7; j++) {
            printf("%.1f ", weather_temp[i][j]);
        }
        printf("\n");
    }

    printf("\n The average temperature of each city:\n");
    for(i = 0; i < 5; i++) {
        float sum = 0;
        for(j = 0; j < 7; j++) {
            sum = sum + weather_temp[i][j];
        }
        avg[i] = sum / 7;
    }

    for(i = 0; i < 5; i++) {
        printf("City %d: %.2f\n", i + 1, avg[i]);
    }

    float highest = avg[0];
    int cityIndex = 0;
    for(i = 1; i < 5; i++) {
        if(avg[i] > highest) {
            highest = avg[i];
            cityIndex = i;
        }
    }

    printf("\nCity %d has the highest average temperature: %.2f\n", cityIndex + 1, highest);

    return 0;
}

