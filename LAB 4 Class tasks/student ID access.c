#include<stdio.h>
int main(){
	int id=2008;
	printf("Enter your  last 4 digits of student ID: ");
	scanf("%d", &id);
	
	if(id==2008){
		printf("Valid User: Proceed to login");
	}else{
		printf("Unknown User: Access Denied");
	}
	return 0;
}
