#include <stdio.h>

#define N 4   // number of students

typedef struct {
    int id;
} Student;

// return 1 if found, else 0
int hasId(Student a[], int n, int key);

int main(void) {
    Student list[N];
    int key;
    int ok;

    // input ids
    printf("Enter %d student IDs:\n", N);
    for (int i = 0; i < N; i++) {
        printf("ID of student %d: ", i + 1);
        scanf("%d", &list[i].id);
    }

    // search key
    printf("\nID to search: ");
    scanf("%d", &key);

    ok = hasId(list, N, key);

    // report
    printf("\n=== SEARCH RESULT ===\n");
    printf("IDs: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", list[i].id);
    }
    printf("\nQuery: %d\n", key);

    if (ok)
        printf("Status: FOUND\n");
    else
        printf("Status: NOT FOUND\n");

    return 0;
}

int hasId(Student a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i].id == key)
            return 1;
    }
    return 0;
}
