#include<stdio.h>
int main(){
	int days,usage;
	printf("Enter monthly usage of water (liters): ");
	scanf("%d", &usage);
	printf("Enter number of days water was saved: ");
	scanf("%d", &days);
	
	if(usage<2500 && days>10){
		printf("Bonus: 300 PKR Discount");
		
	}else{
		printf("No Bonus");
	}
	return 0;
}

