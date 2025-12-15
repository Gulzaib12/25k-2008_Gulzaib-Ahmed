#include <stdio.h>
#include <string.h>

const int CITY_ROAD = 0;
const int HIGHWAY = 1;
const int MOUNTAIN = 2;
const int MAX_ROAD_TYPES = 3;
const int SEGMENT_LENGTH_KM = 10;
const int SEGMENT_CHARGE_CENTS[] = {50, 150, 300};

typedef struct Route {
    char route_id[20];
    int total_distance_km;
    int base_price_cents;
    int road_type;
    int final_cost_cents;
} Route;

void calculate_segment_cost_recursive(int remaining_distance_km, int charge_per_segment, int segment_length, int *final_cost_cents) {
    if (remaining_distance_km <= 0) {
        return;
    }

    *final_cost_cents += charge_per_segment;

    int next_remaining_distance = remaining_distance_km - segment_length;

    calculate_segment_cost_recursive(next_remaining_distance, charge_per_segment, segment_length, final_cost_cents);
}

int main() {
    Route delivery;
    char *input_result;
    int scan_result;
    int selected_type_index;
    memset(&delivery, 0, sizeof(Route));

    printf("Delivery Route Cost Estimator\\n");
    printf("Enter Route ID: ");
    input_result = fgets(delivery.route_id, sizeof(delivery.route_id), stdin);
    if (input_result == NULL) {
        printf("Error reading Route ID.\\n");
        return 1;
    }

    delivery.route_id[strcspn(delivery.route_id, "\\n")] = 0;
    int base_price;
    printf("Enter Base Delivery Price : ");
    scan_result = scanf("%d", &base_price);
    if (scan_result != 1) {
        printf("Invalid input format for base price.\\n");
        return 1;
    }

    if (base_price < 0) {
        printf("Base delivery price cannot be negative.\\n");
        return 1;
    }

    delivery.base_price_cents = base_price * 100;

    printf("Enter Total Route Distance (in kilometers): ");
    scan_result = scanf("%d", &delivery.total_distance_km);

    if (scan_result != 1) {
        printf("Invalid input format for distance.\\n");
        return 1;
    }

    if (delivery.total_distance_km < 0) {
        printf("Error: Total distance cannot be negative.\\n");
        return 1;
    }

    printf("Enter Road Type Index (0=City, 1=Highway, 2=NO SPECIFIC CHOICE): ");
    scan_result = scanf("%d", &selected_type_index);

    if (scan_result != 1) {
        printf("Invalid input format for road type index.\\n");
        return 1;
    }

    if (selected_type_index < CITY_ROAD || selected_type_index >= MAX_ROAD_TYPES) {
        printf("Road type index must be between 0 and %d.\\n", MAX_ROAD_TYPES - 1);
        return 1;
    }

    delivery.road_type = selected_type_index;
    delivery.final_cost_cents = delivery.base_price_cents;
    int charge = SEGMENT_CHARGE_CENTS[delivery.road_type];

    calculate_segment_cost_recursive(delivery.total_distance_km, charge, SEGMENT_LENGTH_KM, &delivery.final_cost_cents);

    printf("\nFinal Route Cost Estimation\\n");
    printf("Route ID: %s\\n", delivery.route_id);
    printf("Total Distance: %d km\\n", delivery.total_distance_km);
    printf("Road Type: %s (Charge: X.%2f/segment)\\n",
           (delivery.road_type == CITY_ROAD) ? "City" : (delivery.road_type == HIGHWAY) ? "Highway" : "NO SPECIFIC CHOICE",
           (float)SEGMENT_CHARGE_CENTS[delivery.road_type] / 100.0);
    printf("Base Cost: %.2f\\n", (float)delivery.base_price_cents / 100.0);
    printf("Total Final Cost: %.2f\\n", (float)delivery.final_cost_cents / 100.0);

    return 0;
}

