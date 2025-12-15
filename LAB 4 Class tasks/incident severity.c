#include<stdio.h>
main(){
	int code;
	printf("Enter  severity code (1-4): ");
	scanf("%d", &code);
	
	switch(code){
		case 1: 
		       printf(" Low (Unusual login time)");
		        break;
	
		case 2:
			  printf(" Medium (Suspicious failed attempts)");
		    	break;
			
		case 3:
		       printf(" High (Multiple accounts targeted)");
		        break;
		       
		case 4:
			  printf(" Critical (Brute-force/DDoS attack detected)");
			   break;
		
		default: 
		       printf("Invalid Code: Enter a number between 1 and 4");
		       
	}
	return 0;
}
