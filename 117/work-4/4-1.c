#include <stdio.h>

// function prototype
void set_ptr(int **dst, int *src);

int main(void) {
    int *ptr = NULL;
    int x = 10, y = 20;

    // make ptr point to x
    set_ptr(&ptr, &x);
    printf("%d %p %p\n", *ptr, ptr, &ptr);

    // make ptr point to y
    set_ptr(&ptr, &y);
    printf("%d %p %p\n", *ptr, ptr, &ptr);

    return 0;
}

// change where pointer points
void set_ptr(int **dst, int *src) {
    *dst = src;
}
