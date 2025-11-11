#include<stdio.h>
void main()
{
struct student{
    char name[20];
    int age;
    float grade;
};
void acceptByValue(struct student student) {
printf("Enter student name:");
scanf ("%s", student.name);
printf("Enter age:");
scanf("%d", &student.age);
printf("Enter grade:");
scanf("%f", &student.grade);
printf("Name:%s,Age:%d,Grade:%f",student.name,student.age,student.grade);
}

void acceptByReference(struct student *student) {
printf("Enter student name:");
scanf("%s", student->name);
printf("Enter age:");
scanf("%d", &student.age);
printf("Enter grade:");
scanf("%f", &student->grade);
}

void displaystudent(struct student student) {
    printf("\n DISPLAYING STUDENT DETAILS:\n");
    printf("Name:%s\nAge:%d\nGrade:%f\n",student.name,student.age,student.grade);
}

{

    struct student s1,s2;

    printf("Enter the details for student 1: (Pass by value)\n");
    acceptByValue(s1);

    printf("Enter the details for student 2: (Pass by reference)\n");
    acceptByReference(&s2);

    printf("\nStudent 1 details:\n");
    displaystudent(s1);

    printf("\nStudent 2 details:\n");
    displaystudent(s2);
}
}
