#include <stdio.h>

typedef struct {
    int id;
    int salary;
    int bonus;
} Employee;

// compute take-home income
int calcNet(Employee e);

int main(void) {
    Employee emp;
    int net = 0;

    // input fields
    scanf("%d", &emp.id);
    scanf("%d", &emp.salary);
    scanf("%d", &emp.bonus);

    // compute
    net = calcNet(emp);

    // report
    printf("\n=== EMPLOYEE REPORT ===\n");
    printf("ID: %d\n", emp.id);
    printf("Salary: %d\n", emp.salary);
    printf("Bonus: %d\n", emp.bonus);
    printf("Net income: %d\n", net);

    return 0;
}

// apply simple tax rule
int calcNet(Employee e) {
    int gross = e.salary + e.bonus;
    float rate = (gross > 30000) ? 0.10f : 0.05f;
    return (int)(gross * (1.0f - rate));
}
