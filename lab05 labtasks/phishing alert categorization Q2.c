#include<stdio.h>
int main() {
    int email_type, user_action;
    printf("Enter phishing email type (1 = Fake Login Page, 2 = Malicious Link, 3 = Urgent Money Request): ");
    scanf("%d", &email_type);

    switch(email_type) {
        case 1:
            printf("Enter user action (1 = Clicked, 2 = Reported, 3 = Ignored): ");
            scanf("%d", &user_action);
            switch(user_action) {
                case 1:
                    printf("Severity:High Risk");
                    break;
                case 2:
                    printf("Severity:Medium Risk");
                    break;
                case 3:
                    printf("Severity:Low Risk");
                    break;
                default:
                    printf("Invalid Input");
            }
            break;
        case 2:
            printf("Enter user action (1 = Clicked, 2 = Reported, 3 = Ignored): ");
            scanf("%d", &user_action);
            switch(user_action) {
                case 1:
                    printf("Severity:High Risk");
                    break;
                case 2:
                    printf("Severity:Medium Risk");
                    break;
                case 3:
                    printf("Severity:Low Risk");
                    break;
                default:
                    printf("Invalid Input");
            }
            break;

        case 3:
            printf("Enter user action (1 = Clicked, 2 = Reported, 3 = Ignored): ");
            scanf("%d", &user_action);
            switch(user_action) {
                case 1:
                    printf("Severity:High Risk");
                    break;
                case 2:
                    printf("Severity:Medium Risk");
                    break;
                case 3:
                    printf("Severity:Low Risk");
                    break;
                default:
                    printf("Invalid Input");
            }
            break;
        default:
            printf("Invalid Input");
    }

    return 0;
}
