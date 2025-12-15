#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct hospitalBed {
    int isOccupied;
    char patientName[50];
    int daysAdmitted;
};

struct Ward {
    struct hospitalBed* beds;
    int totalBeds;
};

struct Ward *createWard(int beds) {
    struct Ward* ward = (struct Ward*)malloc(sizeof(struct Ward));
    ward->beds = (struct hospitalBed*)malloc(beds * sizeof(struct hospitalBed));
    ward->totalBeds = beds;

    int i;
    for (i = 0; i < beds; i++) {
        ward->beds[i].isOccupied = 0;
        strcpy(ward->beds[i].patientName, "");
        ward->beds[i].daysAdmitted = 0;
    }
    return ward;
}

int countOccupied(struct hospitalBed* beds, int n) {
    int count = 0;
    int i;
    for (i = 0; i < n; i++) {
        if (beds[i].isOccupied) {
            count++;
        }
    }
    return count;
}

void admitPatient(struct Ward* ward) {
    int bedNumber;
    printf("Enter bed number to admit patient (1-%d): ", ward->totalBeds);
    scanf("%d", &bedNumber);

    if (bedNumber < 1 || bedNumber > ward->totalBeds) {
        printf("Invalid bed number!\n");
        return;
    }

    if (ward->beds[bedNumber - 1].isOccupied) {
        printf("Bed is already occupied!\n");
        return;
    }

    printf("Enter patient name: ");
    scanf(" %[^\n]s", ward->beds[bedNumber - 1].patientName); // Use %[^\n]s for multi-word names

    printf("Enter days admitted: ");
    scanf("%d", &ward->beds[bedNumber - 1].daysAdmitted);

    ward->beds[bedNumber - 1].isOccupied = 1;
    printf("Patient admitted successfully!\n");
}

void dischargePatient(struct Ward* ward) {
    int bedNumber;
    printf("Enter bed number to discharge patient (1-%d): ", ward->totalBeds);
    scanf("%d", &bedNumber);

    if (bedNumber < 1 || bedNumber > ward->totalBeds) {
        printf("Invalid bed number!\n");
        return;
    }

    if (!ward->beds[bedNumber - 1].isOccupied) {
        printf("Bed is already free!\n");
        return;
    }

    ward->beds[bedNumber - 1].isOccupied = 0;
    strcpy(ward->beds[bedNumber - 1].patientName, "");
    ward->beds[bedNumber - 1].daysAdmitted = 0;
    printf("Patient discharged successfully!\n");
}

void saveWard(struct Ward* ward, FILE* file) {
    fprintf(file, "%d\n", ward->totalBeds);

    int i;
    for (i = 0; i < ward->totalBeds; i++) {
        fprintf(file, "%d %d %s\n", ward->beds[i].isOccupied, ward->beds[i].daysAdmitted, ward->beds[i].patientName);
    }
}

struct Ward *loadWard(FILE* file) {
    int beds;
    fscanf(file, "%d", &beds);
    struct Ward* ward = createWard(beds);

    int i;
    for (i = 0; i < beds; i++) {
        fscanf(file, "%d %d", &ward->beds[i].isOccupied, &ward->beds[i].daysAdmitted);
        fscanf(file, " %[^\n]s", ward->beds[i].patientName);
    }
    return ward;
}

int main() {
    int wards;
    printf("Enter number of wards: ");
    scanf("%d", &wards);

    struct Ward** hospital = (struct Ward**)malloc(wards * sizeof(struct Ward*));
    int wardIndex = 0;

    printf("Enter your choice (1) Load from file or (2) Create new ward: ");
    int choice;
    scanf("%d", &choice);

    if (choice == 1) {
        FILE* file = fopen("hospital.txt", "r");
        if (!file) {
            printf("File not found! Creating new ward.\n");
            choice = 2;
        } else {
            hospital[wardIndex] = loadWard(file);
            fclose(file);
        }
    }

    if (choice == 2) {
        int beds;
        printf("Enter number of beds for ward %d: ", wardIndex + 1);
        scanf("%d", &beds);
        hospital[wardIndex] = createWard(beds);
    }

    int option;
    do {
        printf("\n1. Admit Patient\n2. Discharge Patient\n3. Count Occupied Beds\n4. Save and Exit\n");
        printf("Enter choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1: admitPatient(hospital[wardIndex]); break;
            case 2: dischargePatient(hospital[wardIndex]); break;
            case 3:
                printf("Occupied beds: %d\n", countOccupied(hospital[wardIndex]->beds, hospital[wardIndex]->totalBeds));
                break;
            case 4: {
                FILE* file = fopen("hospital.txt", "w");
                saveWard(hospital[wardIndex], file);
                fclose(file);
                printf("State saved.\n");
                break;
            }
            default: printf("Invalid option!\n");
        }
    } while (option != 4);

    int i;
    for (i = 0; i < wards; i++) {
        if (hospital[i]) {
            free(hospital[i]->beds);
            free(hospital[i]);
        }
    }
    free(hospital);

    return 0;
}
