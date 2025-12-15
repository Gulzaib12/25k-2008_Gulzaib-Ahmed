#include<stdio.h>
main(){
	float subject1,subject2,subject3,subject4,subject5;
	printf("Enter your subj01 (PF) Marks: ");
	scanf("%f", &subject1);
	
	printf("Enter your subj02 (AP) Marks: ");
	scanf("%f", &subject2);
	
	printf("Enter your subj03 (CAL) Marks: ");
	scanf("%f", &subject3);
	
	printf("Enter your subj04 (IST) Marks: ");
	scanf("%f", &subject4);
	
	printf("Enter your subj05 (ICP) Marks: ");
	scanf("%f", &subject5);
	
	float total=subject1+subject2+subject3+subject4+subject5;
	float percentage=total/500*100;
	float cgpa=(percentage/100)*4;
	
	printf("\n--------------------------------\n");
	printf(" STUDENT RESULT ");
	printf("\n--------------------------------\n");
	printf("Marks: %.2f %.2f %.2f %.2f %.2f", subject1,subject2,subject3,subject4,subject5);
	printf("\nTotal: %.2f\n", total);
	printf("Percentage: %.2f%%\n", percentage);
	printf("CGPA: %.2f/4.00", cgpa);
	printf("\n--------------------------------\n");
	return 0;		
}





