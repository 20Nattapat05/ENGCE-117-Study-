#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float score;
    char name[50];
} Student;

// read one
static int read_one(Student *s) {
    return scanf("%d %f %49s", &s->id, &s->score, s->name) == 3;
}

// check pass
static int is_pass(float sc) {
    return sc >= 60.0f; // pass rule
}

int main(void) {
    int n = 0;
    int pass = 0;  // pass cnt
    int fail = 0;  // fail cnt

    if (scanf("%d", &n) != 1 || n <= 0) return 1; // bad n

    Student *arr = (Student *)malloc((size_t)n * sizeof(*arr));
    if (!arr) return 1; // no mem

    for (int i = 0; i < n; ++i) {
        if (!read_one(&arr[i])) { // bad input
            free(arr);
            return 1;
        }

        if (is_pass(arr[i].score))  // test
            ++pass;
        else
            ++fail;
    }

    printf("Pass Count: %d\n", pass); // out pass
    printf("Fail Count: %d\n", fail); // out fail

    free(arr); // cleanup
    return 0;  // ok
}
