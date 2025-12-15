#include<stdio.h>
main(){
	int attempts;
	printf(" provide number of failed login attempts: ");
	scanf("%d", &attempts);
	
	if(attempts==0){
		printf("No suspicious activity");
	}else if(attempts>=1 && attempts<=3){
		printf("Warning: User may have forgotten password");
	}else if(attempts>=4 && attempts<=6){
		printf("Alert: Possible unauthorized access attempt");
	}else{
		printf("Critical: Account Locked due to brute-force attempt");
	}
	
	return 0;
}
