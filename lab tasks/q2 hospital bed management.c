#include<stdio.h>

int main()
{
    int hospital[4][6];
    int i,j;
    int occupied=0;
    int vacant=0;

    printf("Enter 0 for (vacant) or 1 for (occupied) for each room:\n");

    for(i=0;i<4;i++){
        printf("\nWard: %d\n",i+1);
        for(j=0;j<6;j++){
            printf("Room: %d: ",j+1);
            scanf("%d", &hospital[i][j]);
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 6; j++) {
            if(hospital[i][j] == 1) {
                occupied++;
            }
            else {
                vacant++;
            }
        }
    }

    int maxWard = 0;
    int maxOccupied = 0;
    for(i = 0; i < 4; i++) {
        int wardOccupied = 0;
        for(j = 0; j < 6; j++) {
            if(hospital[i][j] == 1) {
                wardOccupied++;
            }
        }

        if(wardOccupied > maxOccupied) {
            maxOccupied = wardOccupied;
            maxWard = i;
        }
    }

    printf("\nTotal occupied beds: %d\n", occupied);
    printf("Total vacant beds: %d\n", vacant);
    printf("Ward %d has maximum occupancy: %d beds\n", maxWard + 1, maxOccupied);

    if(maxOccupied < 4) {
        printf("Increase Admission Drive\n");
    }

    return 0;
}

