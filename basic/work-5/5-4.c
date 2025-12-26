#include <stdio.h>

#define N 3   // number of students

typedef struct {
    int id;
    int score;
} Student;

// return id of highest scorer
int bestId(Student a[], int n);

int main(void) {
    Student list[N];
    int champion = -1;

    // input section
    printf("Input data for %d students:\n", N);
    for (int i = 0; i < N; i++) {
        printf("-- Student %d --\n", i + 1);
        printf("ID: ");
        scanf("%d", &list[i].id);
        printf("Score: ");
        scanf("%d", &list[i].score);
    }

    // find top id
    champion = bestId(list, N);

    // report section
    printf("\n=== SCORE SUMMARY ===\n");
    printf("ID     | Score\n");
    printf("-------|------\n");
    for (int i = 0; i < N; i++) {
        printf("%-6d | %d\n", list[i].id, list[i].score);
    }

    printf("\nHighest score belongs to ID: %d\n", champion);

    return 0;
}

int bestId(Student a[], int n) {
    int maxScore = -1;
    int maxId = -1;

    for (int i = 0; i < n; i++) {
        if (a[i].score > maxScore) {
            maxScore = a[i].score;
            maxId = a[i].id;
        }
    }

    return maxId;
}
