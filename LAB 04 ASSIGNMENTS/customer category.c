#include<stdio.h>
int main(){
	int category;
	printf("Enter your category code (1-4): ");
	scanf("%d", &category);
	
	switch(category){
		
		case 1: 
		        printf("Low Usage Household");
		        break;
		case 2:
			    printf("Average Household");
			    break;
		case 3:
			    printf("High Usage Household");
			    break;
		case 4:
			    printf("Excessive Usage Household");
			    break;
		default:
			    printf("Invalid Category Code");
	}
	return 0;
	
}

