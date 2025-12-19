#include <stdio.h>

int main(void) {
    int level, age, active;
    int access = 0;

    if (scanf("%d %d %d", &level, &age, &active) != 3) {
        return 1;
    }

    if (active && (level == 3 || (level == 2 && age >= 25))) {
        access = 1;
    }

    if (access)
        printf("Access Granted\n");
    else
        printf("Access Denied\n");

    return 0;
}
