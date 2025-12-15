#include<stdio.h>
int main(){
    int attempts, time;
    printf("Enter number of login attempts: ");
    scanf("%d", &attempts);
    printf("Enter time interval (in minutes): ");
    scanf("%d", &time);

    if(attempts>5 && time<10){
        printf("Brute-Force Attack");
    }else if(attempts>3 && time<30){
        printf("Suspicious Activity");
    }else{
        printf("Normal Login Behavior");
    }
    return 0;
}
