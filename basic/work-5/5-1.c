#include <stdio.h>

// compute rectangle area
int area(int h, int w);

int main(void) {
    int len;
    int wid;
    int a;

    printf("Input length: ");
    scanf("%d", &len);

    printf("Input width: ");
    scanf("%d", &wid);

    a = area(len, wid);

    printf("\n=== AREA RESULT ===\n");
    printf("Length = %d\n", len);
    printf("Width  = %d\n", wid);
    printf("Area   = %d\n", a);

    return 0;
}

// simple formula
int area(int h, int w) {
    return h * w;
}
