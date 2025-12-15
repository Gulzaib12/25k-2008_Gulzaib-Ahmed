#include <stdio.h>

int main(){
    int runs = 500;
    int day = 1;
    for(runs;runs<2000;runs=runs*1.05){
        day=day+1;
    }
    printf("TOTAL DAYS JOGGER'S TAKE TO RUN AT LEAST 2Km: %d\n", day);
    printf("Distance run on the final day: %d\n",runs);
    return 0;
}
