
#include<stdio.h>
main(){
	float distance,fuel,fuel_price;
	printf("Enter distance travelled(km): ");
	scanf("%f", &distance);
	
	printf("Enter fuel used(litrs): ");
	scanf("%f", &fuel);
	
	printf("Enter fuel price per litre: ");
	scanf("%f", &fuel_price);
	
	float efficiency=distance/fuel;
	float total_cost=fuel*fuel_price;
	
	printf("\n------------------------\n");
	printf(" FUEL REPORT ");
	printf("\n------------------------\n");
	printf("Distance: %.2f\n", distance);
	printf("Fuel Used: %.2f L\n", fuel);
	printf("Efficiency: %.2f km/L\n", efficiency);
	printf("Total Cost: %.2f PKR\n", total_cost);
	
	return 0;
	
	
	
}


