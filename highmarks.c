#include<stdio.h>
void main()
{
 struct student{
 char name[20];
 int marks;
 };
 struct student s1,s2;
printf("Enter the 1st student name:");
scanf("%s", s1.name);
printf("Enter the marks of student 1:");
scanf("%d", &s1.marks);
printf("Enter the 2nd student name:");
scanf("%s", s2.name);
printf("Enter the marks of student 2:");
scanf("%d", &s2.marks);
if (s1.marks > s2.marks)
 printf("\n%s scored highest than %s",s1.name,s2.name);
else if (s2.marks>s1.marks)
    printf("\n %s scored higher than %s",s2.name,s1.name);
else
    printf("Both the students scored higher marks");
}
