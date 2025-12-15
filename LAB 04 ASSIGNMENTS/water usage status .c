#include<stdio.h>
int main(){
	int usage;
	printf("Enter daily water usage (liters): ");
	scanf("%d", &usage);
	if(usage<=100){
		printf("Efficient Usage");
		
	}else{
		printf("High Usage Dedected");
	}
	return 0;
}


