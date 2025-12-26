#include <stdio.h>

#define NEMP 4   // number of employees

typedef struct {
    int id;
    int salary;
} Emp;

// find min & max via pointers
void minmax(Emp a[], int n, int *pmax, int *pmin);

int main(void) {
    Emp e[NEMP];
    int mx, mn;

    // input
    printf("Enter data for %d employees:\n", NEMP);
    for (int i = 0; i < NEMP; i++) {
        printf("-- Employee %d --\n", i + 1);
        printf("ID: ");
        scanf("%d", &e[i].id);
        printf("Salary: ");
        scanf("%d", &e[i].salary);
    }

    // compute min and max
    minmax(e, NEMP, &mx, &mn);

    // report
    printf("\n=== SALARY REPORT ===\n");
    printf("ID     | Salary\n");
    printf("-------|--------\n");
    for (int i = 0; i < NEMP; i++) {
        printf("%-6d | %d\n", e[i].id, e[i].salary);
    }

    printf("\nMax salary: %d\n", mx);
    printf("Min salary: %d\n", mn);

    return 0;
}

void minmax(Emp a[], int n, int *pmax, int *pmin) {
    *pmax = a[0].salary;
    *pmin = a[0].salary;

    for (int i = 1; i < n; i++) {
        if (a[i].salary > *pmax)
            *pmax = a[i].salary;
        if (a[i].salary < *pmin)
            *pmin = a[i].salary;
    }
}
