#include<stdio.h>
int main(){
	int member,usage;
	printf("Enter number of family member: ");
	scanf("%d", &member);
	printf("Enter monthly usage of water (liters): ");
	scanf("%d", &usage);
	
	if(usage>3000 && member>6){
		printf("Allowed: Large Family Exception");
		
	}else{
		printf("Fine Applied");
	}
	return 0;
}

