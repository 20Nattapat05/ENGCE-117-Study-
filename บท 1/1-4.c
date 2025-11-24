#include <stdio.h>

int main() {
    int N, sum = 0;

    printf("ป้อนตัวเลขจำนวนเต็ม N: ");
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        sum += i;
    }

    printf("ผลรวมของตัวเลขตั้งแต่ 1 ถึง %d คือ: %d\n", N, sum);

    return 0;
}
