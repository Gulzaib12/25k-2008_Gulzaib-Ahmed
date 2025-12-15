
          #include<stdio.h>
main(){
	float eggs,bread,butter;
	
	printf(" Enter eggs price: ");
	scanf("%f", &eggs);
	
	printf(" Enter bread price: ");ss
	scanf("%f", &bread);
	
	printf(" Enter butter price: ");
	scanf("%f", &butter);
	
	float subtotal=eggs+bread+butter;
	float tax=subtotal*17/100;
	float grand_total=subtotal+tax;
	
	printf("\n---------------------------\n");
	printf("  SHOP RECEIPT ");
	printf("\n---------------------------\n");
	printf("Eggs Price: %.2f\n", eggs);
	printf("Bread Price: %.2f\n", bread);
	printf("Butter Price: %.2f\n", butter);
	printf("\n----------------------------\n");
	printf("Subtotal: %.2f\n", subtotal);
	printf("Tax(17%%): %.2f\n", tax);
	printf("\n----------------------------\n");
	printf("Grand Total: %.2f", grand_total);
	
	return 0;
}
