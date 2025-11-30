#include <stdio.h>
#include <stdlib.h>

void GetSet(int **data, int *num);

int main() {
    int *data;
    int num;

    GetSet(&data, &num);

    printf("\nสมาชิกในเซตที่รับมา:\n");
    for(int i = 0; i < num; i++){
        printf("%d ", data[i]);
    }

    free(data);
    return 0;
}

void GetSet(int **data, int *num) {
    printf("จำนวนสมาชิก: ");
    scanf("%d", num);

    *data = malloc(*num * sizeof(int));

    printf("ป้อนค่าทีละสมาชิก:\n");
    for(int i = 0; i < *num; i++){
        printf("สมาชิก %d: ", i+1);
        scanf("%d", &(*data)[i]);
    }
}
