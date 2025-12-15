#include <stdio.h>
#include <string.h>

struct person{
	char name[100];
	int age;
};

struct student{
	struct person person;
	int credit_hours;
	float percredit_fee;
};

float calculate_fee(struct student student, int subjects, int current_sub);

int main(){
	struct student student;
	int subjects;

	printf("ENTER STUDENT NAME: ");
	scanf("%[^\n]",student.person.name);
	printf("ENTER STUDENT'S AGE: ");
	scanf("%d",&student.person.age);
	printf("Enter credit hours: ");
	scanf("%d",&student.credit_hours);
	printf("Enter per credit Fee: ");
	scanf("%f",&student.percredit_fee);
	printf("Enter no of Subjects: ");
	scanf("%d",&subjects);

	float totalFee= calculate_fee(student,subjects,0);

	printf("STUDENT NAME: %s\n", student.person.name);
	printf("TOTAL SEMESTER FEE FOR %d SUBJECTS: %.2f\n", subjects,totalFee);

	return 0;
}

float calculate_fee(struct student student, int subjects, int current_sub){
	if(current_sub==subjects){
		return 0;
	}
	else{
		return (student.percredit_fee * student.credit_hours) + calculate_fee(student,subjects,current_sub +1);
	}
}

