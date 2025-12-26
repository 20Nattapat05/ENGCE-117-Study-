#include <stdio.h>

// compute net balance and set status flag (profit/loss)
int netBalance(const int *arr, int n, int *pstatus);

int main(void) {
    const int N = 5;
    int t[N];
    int status;
    int balance;

    printf("Enter %d transactions (+income / -expense):\n", N);
    for (int i = 0; i < N; i++) {
        printf("Tx %d: ", i + 1);
        scanf("%d", &t[i]);
    }

    // calculate
    balance = netBalance(t, N, &status);

    // show all
    printf("\n=== TRANSACTION SUMMARY ===\n");
    printf("List: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", t[i]);
    }

    printf("\nNet balance: %d\n", balance);
    printf("Result: %s\n", status ? "Profit" : "Loss");

    return 0;
}

int netBalance(const int *arr, int n, int *pstatus) {
    int total = 0;

    while (n--) {
        total += *arr;
        arr++;         // move pointer
    }

    // 1 = profit or break-even, 0 = loss
    *pstatus = (total >= 0);
    return total;
}
