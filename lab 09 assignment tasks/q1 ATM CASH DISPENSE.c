#include <stdio.h>
int cash_dispense(int withdrawal_amount, int denomination_counts);
int main () {
    int withdrawal_amount;
    int denomination_counts[3];
    
    printf("\nATM Cash Dispenser\n");
    printf("Enter your withdrawal amount (multiple of 50): ");
    scanf("%d", &withdrawal_amount);
    
    int result_remainder = cash_dispense(withdrawal_amount, denomination_counts); 
    
    if(result_remainder == 0) {
        printf("DENOMINATIONS OF 5000: %d\n", denomination_counts[0]);
        printf("DENOMINATIONS OF 1000: %d\n", denomination_counts[1]);
        printf("DENOMINATIONS OF 500: %d\n", denomination_counts[2]);
    }
    
    return 0;
}

int cash_dispense(int amount, int *counts) {
    if (amount <= 0 || amount % 50 != 0) {
        printf("Invalid withdrawal amount! Amount must be a multiple of 50.\n");
    } else {
        int remaining_amount = amount;
        int note_count;
        
        note_count = remaining_amount / 5000;
        *(counts + 0) = note_count;
        remaining_amount = remaining_amount % 5000;
        
        note_count = remaining_amount / 1000;
        *(counts + 1) = note_count;
        remaining_amount = remaining_amount % 1000;
        
        note_count = remaining_amount / 500;
        *(counts + 2) = note_count;
        remaining_amount = remaining_amount % 500;
        
        return remaining_amount;
    }
    return amount; 
}
