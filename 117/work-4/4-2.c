#include <stdio.h>

// prototypes
void updateRef(int ***target, int **source);
void printInfo(const char *label, int **pp);

int main(void)
{
    int a = 10;
    int b = 20;
    int *pa = &a;
    int *pb = &b;
    int **handle = NULL;

    // link to a
    updateRef(&handle, &pa);
    printInfo("After pointing to a", handle);

    // link to b
    updateRef(&handle, &pb);
    printInfo("After pointing to b", handle);

    return 0;
}

// set double pointer via triple pointer
void updateRef(int ***target, int **source)
{
    *target = source;
}

// show pointer chain
void printInfo(const char *label, int **pp)
{
    printf("%s\n", label);
    printf("Value via **pp: %d\n", **pp);
    printf("*pp (points to int*): %p\n", (void *)*pp);
    printf("pp  (int** itself):   %p\n\n", (void *)pp);
}
