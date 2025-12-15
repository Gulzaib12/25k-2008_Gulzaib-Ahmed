#include<stdio.h>
#include<math.h>
int main(){
    int rides_request;
    float surge_multiplier;
    printf("Enter number of rides request in an area: ");
    scanf("%d", &rides_request);

    surge_multiplier=sqrt(rides_request)/2;
    if(surge_multiplier>3){
        surge_multiplier=3;
    }
    printf("FINAL SURGE MULTIPLIER IS: %.2f", surge_multiplier);

    return 0;
}

