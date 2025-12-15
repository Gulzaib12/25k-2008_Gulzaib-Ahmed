#include<stdio.h>
#include<math.h>
main(){
	float p;//loanamount
	float r;//annual_interestrate
	int loan_duration;
	
	printf(" Enter loan amount: ");
	scanf("%f", &p);
	printf(" Enter Annual interest rate (%%): ");
	scanf("%f", &r);
	printf(" Enter loan duration (years): ");
	scanf("%d", &loan_duration);
     float monthly_rate = (r / 100) / 12;	
     int n= loan_duration*12;

    float emi = (p * (monthly_rate * pow(1 + monthly_rate, n)))/ (pow(1 + monthly_rate, n) - 1);

    printf("\n=======================\n");
    printf(" LOAN CALCULATOR");
    printf("\n=======================\n");
    printf(" Loan Amount: %.2f\n", p);
    printf("Duration: %d years",loan_duration);
    printf("(%d months)",n);
    printf("\nInterest rate: %.2f%% per year\n", r);
    printf("Monthly EMI: %.2f\n", emi);
    return 0;

}
