#include <stdio.h>
#include <stdlib.h>

// Employee structure
struct employee
{
    char name[25];
    int hireDate;
    float salary;
};

// Prototyping a function to print employees
void printEmployees(struct employee employee_name);

int main()
{
    // Declaring and initializing an instance of an employee
    struct employee eliot = {"Eliot", 2018, 5046.65};
    struct employee meghan = {"Meghan", 2016, 9418.97};
    struct employee new_employee;

    // Read/store new employee from console
    printf("Name: ");
    scanf("%s", &new_employee.name);
    printf("Date hired: ");
    scanf("%d", &new_employee.hireDate);
    printf("Salary: ");
    scanf("%f", &new_employee.salary);

    // Printing employees
    printEmployees(eliot);
    printEmployees(meghan);
    printEmployees(new_employee);

    return 0;
}

// Function 1: Printing employees from a struct
void printEmployees(struct employee employee_name)
{
    printf("\n---\n");
    printf("Name: %s\n", employee_name.name);
    printf("Date hired: %d\n", employee_name.hireDate);
    printf("Salary: %.2f\n", employee_name.salary);
    printf("---\n");
}
