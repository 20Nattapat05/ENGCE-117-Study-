#include <stdio.h>

/* function prototype */
void moveTower(int disks, int start, int end);

int main()
{
    int total = 3;   // number of disks

    moveTower(total, 1, 3);

    return 0;
}

/* Tower of Hanoi recursive function */
void moveTower(int disks, int start, int end)
{
    if (disks <= 0)
        return;   // base case

    int middle = 6 - start - end;   // calculate middle rod

    /* move n-1 disks to middle rod */
    if (disks > 1)
        moveTower(disks - 1, start, middle);

    /* move largest disk */
    printf("Move disk %d from rod %d to rod %d\n", disks, start, end);

    /* move n-1 disks to destination */
    if (disks > 1)
        moveTower(disks - 1, middle, end);
}