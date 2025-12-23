#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float score;
    char name[50];
} Student;

// read one
static int read_one(Student *p) {
    return scanf("%d %f %49s", &p->id, &p->score, p->name) == 3;
}

// print one
static void print_one(const Student *p) {
    printf("Student ID: %d\n", p->id);
    printf("Name: %s\n", p->name);
    printf("Score: %.2f\n", p->score);
    printf("--------------------\n");
}

int main(void) {
    int n = 0;

    if (scanf("%d", &n) != 1 || n <= 0) return 1; // bad n

    Student *arr = (Student *)malloc((size_t)n * sizeof(*arr));
    if (!arr) return 1; // no mem

    for (int i = 0; i < n; ++i) {
        if (!read_one(&arr[i])) { // bad input
            free(arr);
            return 1;
        }
    }

    puts("\n--- Student List ---"); // header
    for (int i = 0; i < n; ++i) {
        print_one(&arr[i]); // show
    }

    free(arr); // cleanup
    return 0;  // ok
}
