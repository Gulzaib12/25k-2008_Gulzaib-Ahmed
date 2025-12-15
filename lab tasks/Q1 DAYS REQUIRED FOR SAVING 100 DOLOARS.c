#include <stdio.h>

int main () {
    int day = 1;
    int savings = 0;
    for(savings; savings<100;day++){
        savings=savings+day;
    }
    printf("Total taking days of amount: %d", day);
    return 0;
}
