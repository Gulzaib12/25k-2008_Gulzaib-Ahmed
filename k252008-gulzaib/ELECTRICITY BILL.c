#include<stdio.h>
main(){
	char name[100];
	int units;
	float priceper_unit;
	
	printf("Enter customer name:  ");
	scanf("%s", &name);
	
	printf("Enter units consumed: ");
	scanf("%d", &units);
	
	printf("Enter price of per unit: ");
	scanf("%f", &priceper_unit);
	
	float total_bill=priceper_unit*units;
	printf("\n----------------------------------\n");
	printf("    ELECTRICITY BILL    ");
	printf("\n----------------------------------\n");
	printf("Customer: %s\n", name);
	printf("Units Consumed: %d\n", units);
	printf("Price Per Unut: %.2f\n", priceper_unit);
	printf("\n---------------------------------\n");
	printf("Total Bill: %.2f", total_bill);
	printf(" PKR");
	return 0;
	
}   


