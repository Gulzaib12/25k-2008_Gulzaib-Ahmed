#include <stdio.h>

const char* get_category(float avg);
void calculate_average(int (*mileage_data)[7], float *average_results);
void report_compact(char vehicle_names[5][20], float *avg_results);
void report_detailed(char vehicle_names[5][20], float *avg_results);
typedef void (*ReportPtr)(char [5][20], float *);
int vehicles = 5;
int days = 7;
int i, j;

int main() {
    int daily_mileage[5][7];
    char vehicle_names[5][20] = {"Truck 1", "Van 2", "Bus 3", "Car 4", "Lorry 5"};
    float average_mileages[5];

    printf("\n Vehicle Mileage Tracker Program (km/l)\n");
    printf("\n Please enter the daily mileage (km/l) for each vehicle:\n");

    for (i = 0; i < vehicles; i++) {
        printf("\n Entering data for %s \n", vehicle_names[i]);
        for (j = 0; j < days; j++) {
            printf(" Day %d mileage: ", j + 1);
            if (scanf("%d", &daily_mileage[i][j]) != 1) {
                printf("Error reading input. Exiting.\n");
                return 1;
            }
        }
    }

    printf("\n Calculating Averages\n");
    calculate_average(daily_mileage, average_mileages);

    int choice;
    ReportPtr reporter;

    printf("\n Select Report Format:\n");
    printf("Enter choice (1 or 2): 1. Compact Report 2.Detailed Report: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 2) {
        printf("Invalid choice, defaulting to Detailed Report.\n");
        choice = 2;
    }

    if (choice == 1) {
        reporter = report_compact;
    } else {
        reporter = report_detailed;
    }

    printf("\n Report \n");
    reporter(vehicle_names, average_mileages);

    return 0;
}

void calculate_average(int (*mileage_data)[7], float *average_results) {
    for (i = 0; i < vehicles; i++) {
        int total_mileage = 0;
        for (j = 0; j < days; j++) {
            total_mileage += mileage_data[i][j];
        }
        average_results[i] = (float)total_mileage / days;
    }
}

const char* get_category(float avg) {
    if (avg > 18.0) {
        return "Efficient";
    } else if (avg >= 12.0) {
        return "Moderate";
    } else {
        return "Poor";
    }
}

void report_compact(char vehicle_names[5][20], float *avg_results) {
    printf("\n Compact Report \n");
    printf("Vehicle Avg Mileage (km/l) Category \n");

    for (i = 0; i < vehicles; i++) {
        printf("%-7s %-10.2f %s \n", vehicle_names[i], avg_results[i], get_category(avg_results[i]));
    }
}

void report_detailed(char vehicle_names[5][20], float *avg_results) {
    printf("\n Detailed Report \n");
    for (i = 0; i < vehicles; i++) {
        printf("Vehicle: %s\n", vehicle_names[i]);
        printf("Average Mileage: %.2f km/l\n", avg_results[i]);
        printf("Efficiency Category: %s\n", get_category(avg_results[i]));
    }
}

