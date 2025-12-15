#include <stdio.h>

int i, j; 

void highest_Temp(int (*arr)[4]);

int main() {
    int patient_Temp[5][4]; 
    
    for(i = 0; i < 5; i++) {
        printf("\nEnter the temperatures for patient %d:\n", i + 1);
        for(j = 0; j < 4; j++) { 
            printf("Reading %d: ", j + 1);
            scanf("%d", &patient_Temp[i][j]);
        }
    }

    highest_Temp(patient_Temp); 

    return 0; 
}

void highest_Temp(int (*arr)[4]) {
    int highest = 0; 
    
    for(i = 0; i < 5; i++) {
        
        highest = *(*(arr + i) + 0); 
        
        for(j = 1; j < 4; j++) { 
            
            if(*(*(arr + i) + j) > highest) {
                highest = *(*(arr + i) + j);
            }
        }
        
        printf("\n\nHighest temperature for patient %d is %d F\n", i + 1, highest);
        
        if(highest > 101) {
            printf("FEVER DETECTED! \n"); 
        }
    }
}
