#include <stdio.h>
int main(){
    int ride_type;
    char distance;
    int basefare=0;
    printf("Enter your ride type (1 = Economy ,2 = Business, 3 = Luxury): ");
    scanf("%d", &ride_type);

    switch(ride_type){
    case 1:
        printf("Enter your distance (short = s long = l): ");
        scanf(" %c", &distance);
        if(distance =='s'|| distance =='S'){
            basefare=100;
        }else if(distance =='l'|| distance =='L'){
            basefare=300;
        }else{
            printf("Enter valid input\n");
        }
        break;

    case 2:
        printf("Enter your distance (short = s long = l): ");
        scanf(" %c", &distance);
        if(distance =='s'|| distance =='S'){
            basefare=100;
        }else if(distance =='l'|| distance =='L'){
            basefare=300;
        }else{
            printf("Enter valid input\n");
        }
        break;
        case 3:
    printf("Enter your distance (short = s long = l): ");
    scanf(" %c", &distance);
    if(distance =='s'|| distance =='S'){
        basefare=100;
    }else if(distance =='l'|| distance =='L'){
        basefare=300;
    }else{
        printf("Enter valid input\n");
    }
    break;
default:
    printf("Enter valid input\n");
}
printf("Your Ride Fare is: %d\n", basefare);

return 0;
}
