#include<stdio.h>
int main(){
	int usage;
	
	printf("Enter monthly usage of water (liters): ");
	scanf("%d", &usage);
	
	if(usage<=3000){
		printf("No Fine");
		
	}else if(usage>3000 && usage<=5000){
		printf("Fine = 200 PKR");
	}else if(usage>5000 && usage<=7000){
		printf("Fine = 500 PKR");
	}else if(usage>7000){
		printf("Fine = 1000 PKR + Wate Supply Restricted");
	}
	return 0;
}

