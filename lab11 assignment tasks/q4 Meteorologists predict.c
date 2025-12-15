#include <stdio.h>

struct WeatherData {
    char cityName[100];
    float baseTemp;
    float coolingFactor;
};

float predict_Temperature(struct WeatherData weather, int n, int currentDay, float previousTemp);

int main() {
    struct WeatherData weather;
    int num_days;

    printf("Enter City Name: ");
    scanf("%s", weather.cityName);
    printf("Enter Base Temperature: ");
    scanf("%f", &weather.baseTemp);
    printf("Enter Cooling Factor: ");
    scanf("%f", &weather.coolingFactor);
    printf("Enter Number of Days: ");
    scanf("%d", &num_days);

    float temp = predict_Temperature(weather, num_days, 0, weather.baseTemp);
    printf("\nPredicted temperature for %s after %d days: %.2f\n", weather.cityName, num_days, temp);

    return 0;
}

float predict_Temperature(struct WeatherData weather, int num_days, int currentDay, float previousTemp) {
    if (currentDay == num_days) {
        return previousTemp;
    } else {
        float currentTemp = previousTemp - weather.coolingFactor;
        return predict_Temperature(weather, num_days, currentDay + 1, currentTemp);
    }
}

