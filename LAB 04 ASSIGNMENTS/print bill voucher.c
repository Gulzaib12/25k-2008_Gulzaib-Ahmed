#include<stdio.h>
int main(){
	int usage,f_size,code,days;
	printf("Enter monthly usage of water (liters):");
	scanf("%d", &usage);
	printf("Enter number of family member: ");
	scanf("%d", &f_size);
	printf("Enter your category code: ");
	scanf("%d", &code);
	printf("Enter number of days water was saved: ");
	scanf("%d", &days);
	
	switch(code){
		
		case 1: 
		        printf("Low Usage Household\n");
		        break;
		case 2:
			    printf("Average Household\n");
			    break;
		case 3:
			    printf("High Usage Household\n");
			    break;
		case 4:
			    printf("Excessive Usage Household\n");
			    break;
		default:
			    printf("Invalid Category Code\n");
	}
	if(usage<=3000){
		int bill =500;
		printf("Bill = %d\n", bill);
	}else{
		int bill = 1000;
		printf("Bill = %d\n", bill);
		
	}
	if (usage<=3000){
		printf("No fine\n");
	}else if(usage>3000 && usage<=5000){
		printf("Fine = 200 PKR\n");
	}else if(usage>5000 && usage<=7000){
		printf("Fine = 500 PKR\n");
	}else if(usage>7000){
		printf("Fine = 1000 PKR + Wate Supply Restricted\n");
	}
	if(usage<2500 && days>10){
		printf("Bonus: 300 PKR Discount\n");		
	}else{
		printf("No Bonus\n");
	}	
return 0;	
}


