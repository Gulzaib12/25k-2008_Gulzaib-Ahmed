#include <stdio.h>
#include <string.h>

struct Patient {
    char name[100];
    int age;
    float healthScore;
};

struct DailyReport {
    int day;
    float scoreChange;
};

float calculate_HealthScore(struct DailyReport dailyReports[], int no_days, int currentDay, float initialScore);

int main() {
    struct Patient patient;
    int no_days;

    printf("Enter Patient Name: ");
    scanf("%s", patient.name);
    printf("Enter Patient Age: ");
    scanf("%d", &patient.age);
    printf("Enter Initial Health Score: ");
    scanf("%f", &patient.healthScore);
    printf("Enter Number of Days: ");
    scanf("%d", &no_days);

    struct DailyReport dailyReports[no_days];
    for (int i = 0; i < no_days; i++) {
        dailyReports[i].day = i + 1;
        printf("Enter Score Change for Day %d: ", i + 1);
        scanf("%f", &dailyReports[i].scoreChange);
    }

    float finalHealthScore = calculate_HealthScore(dailyReports, no_days, 0, patient.healthScore);
    printf("\nPatient Name: %s\n", patient.name);
    printf("Final Health Score after %d days: %.2f\n", no_days, finalHealthScore);
    
    return 0;
}

float calculate_HealthScore(struct DailyReport dailyReports[], int no_days, int currentDay, float initialScore) {
    if (currentDay == no_days) {
        return initialScore;
    } else {
        float newScore = initialScore + dailyReports[currentDay].scoreChange;
        return calculate_HealthScore(dailyReports, no_days, currentDay + 1, newScore);
    }
}

