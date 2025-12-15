#include<stdio.h>
int main(){
    int age,account_balance;
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Enter your account balance: ");
    scanf("%d", &account_balance);

    if(age<21){
        printf("Not eligible for ride (underage)");
    }
    else if(account_balance<200){
        printf("Not eligible (insufficient balance)");
    }
    else{
        printf("Eligible for ride");
    }
    return 0;
}
