#include<stdio.h>
int main(){
	int usage;
	printf("Enter montly water usage(liters): ");
	scanf("%d", &usage);
	
	if(usage<=3000){
		printf(" Bill = 500 PKR");
	}else{
		printf("Bill = 1000 PKR");
	}
	return 0;
}

