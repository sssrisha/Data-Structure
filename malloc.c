#include <stdio.h>
#include <stdlib.h>

struct employee {
    int id;
    char name[50];
    float salary;
};

int main() {
    int n, i;
    float totalSalary = 0;
    struct employee *ptr;

    printf("Enter the number of employees:\n");
    scanf("%d", &n);

    int memAllocated = n * sizeof(struct employee);

    ptr = (struct employee*)malloc(memAllocated);
    if (ptr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }


    printf("\nMemory allocated: %d bytes\n", memAllocated);


    for (i = 0; i < n; i++) {
        printf("\nEnter details for employee %d:\n", i + 1);

        printf("Enter employee ID: ");
        scanf("%d", &ptr[i].id);

        printf("Enter employee Name: ");
        scanf("%s", ptr[i].name);

        printf("Enter employee Salary: ");
        scanf("%f", &ptr[i].salary);

        totalSalary += ptr[i].salary;
    }


    printf("\n--- Employee Details ---\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", ptr[i].id, ptr[i].name, ptr[i].salary);
    }


    printf("\nTotal Salary of all Employees = %.2f\n", totalSalary);

    free(ptr);
    return 0;
}
