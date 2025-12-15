#include <stdio.h>
#include <string.h>

const int BASE_UNIT_PRICE_CENTS = 1000;
const int TIER_LIMITS[] = {100, 200, 9999999};
const int TIER_TAXES_PERCENT[] = {5, 12, 18};
const int MAX_TIERS = 3;

typedef struct {
    char name[50];
    char meter_id[20];
    int consumed_units;
    int final_bill;
} Customer;

int calculate_tiered_bill(int units_to_process, int current_tier_index) {
    if (units_to_process <= 0 || current_tier_index >= MAX_TIERS) {
        return 0;
    }

    int tier_limit = TIER_LIMITS[current_tier_index];
    int tax_percent = TIER_TAXES_PERCENT[current_tier_index];

    int units_in_tier;
    if (units_to_process > tier_limit) {
        units_in_tier = tier_limit;
    } else {
        units_in_tier = units_to_process;
    }

    int base_cost_in_cents = units_in_tier * BASE_UNIT_PRICE_CENTS;
    int tax_amount = (base_cost_in_cents * tax_percent) / 100;
    int cost_in_tier = base_cost_in_cents + tax_amount;
    int remaining_units = units_to_process - units_in_tier;
    return cost_in_tier + calculate_tiered_bill(remaining_units, current_tier_index + 1);
}

int main() {
    Customer cust;
    char *input_result;
    int scan_result;

    printf("ELECTRICITY BILL CALCULATION \\n");
    printf("Enter Customer Name: ");
    input_result = fgets(cust.name, sizeof(cust.name), stdin);
    if (input_result == NULL) {
        printf("Error reading name input.\\n");
        return 1;
    }

    cust.name[strcspn(cust.name, "\\n")] = 0;
    printf("Enter Meter ID (e.g., MTR-123): ");
    input_result = fgets(cust.meter_id, sizeof(cust.meter_id), stdin);
    if (input_result == NULL) {
        printf("Error reading meter ID input.\\n");
        return 1;
    }

    cust.meter_id[strcspn(cust.meter_id, "\\n")] = 0;

    printf("Enter Total Consumed Units (kWh, whole number only): ");
    scan_result = scanf("%d", &cust.consumed_units);
    if (scan_result != 1) {
        printf("Invalid input for units. Please enter a whole number.\\n");
        return 1;
    }

    if (cust.consumed_units < 0) {
        printf("Units consumed cannot be negative.\\n");
        return 1;
    }

    cust.final_bill = calculate_tiered_bill(cust.consumed_units, 0);

    printf("\\nFinal Bill Statement \\n");
    printf("Customer Name: %s\\n", cust.name);
    printf("Meter ID: %s\\n", cust.meter_id);
    printf("Total Units Consumed: %d kWh\\n", cust.consumed_units);
    printf("Total Payable Amount (Tax inclusive): %.2f\\n", (float)cust.final_bill / 100.0);

    return 0;
}

