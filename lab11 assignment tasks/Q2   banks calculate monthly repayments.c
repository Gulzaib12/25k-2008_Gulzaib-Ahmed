#include <stdio.h>

struct Loan {
    char customerName[100];
    double loanAmount;
    double interestRate;
    double monthlyInstallment;
};

double calculateloan_Payment(double payment, struct Loan *loan);

int main() {
    struct Loan loan;

    printf("Enter Customer Name: ");
    scanf("%99s", loan.customerName);

    printf("Enter your Initial Loan Amount: ");
    scanf("%lf", &loan.loanAmount);

    printf("Enter Interest Rate in decimal (like: 5%% = 0.05 ): ");
    scanf("%lf", &loan.interestRate);

    printf("Enter your Monthly Installment: ");
    scanf("%lf", &loan.monthlyInstallment);

    double finalAmount = calculateloan_Payment(loan.loanAmount, &loan);
    if (finalAmount == -1) {
        printf("\n Monthly installment is too low. Loan will not be paid off.\n");
    } else {
        if (finalAmount <= 0) {
            printf("\nLoan will be paid off.\n");
        } else {
            printf("\nRemaining amount: %.2f\n", finalAmount);
        }
    }

    return 0;
}

double calculateloan_Payment(double payment, struct Loan *loan) {
    if (loan->monthlyInstallment <= payment * loan->interestRate) {
        return -1;
    } else {
        if (payment <= 0) {
            return payment;
        } else {
            double interest = payment * loan->interestRate;
            return calculateloan_Payment(payment + interest - loan->monthlyInstallment, loan);
        }
    }
}

