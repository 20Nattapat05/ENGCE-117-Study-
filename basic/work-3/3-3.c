#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    float score;
    char name[50];
} Student;

// read one
static int read_one(Student *st) {
    return scanf("%d %f %49s", &st->id, &st->score, st->name) == 3;
}

// avg score
static float avg_score(const Student *a, int n) {
    float sum = 0.0f; // sum
    for (int i = 0; i < n; ++i) sum += a[i].score; // add
    return (n > 0) ? (sum / (float)n) : 0.0f; // mean
}

int main(void) {
    int n = 0;

    printf("Enter number of students: "); // prompt
    if (scanf("%d", &n) != 1 || n <= 0) return 1; // bad n

    Student *list = (Student *)malloc((size_t)n * sizeof(*list));
    if (!list) return 1; // no mem

    for (int i = 0; i < n; ++i) {
        printf("Enter details for student %d (ID Score Name): ", i + 1); // prompt
        if (!read_one(&list[i])) { // bad input
            free(list);
            return 1;
        }
    }

    const float avg = avg_score(list, n); // compute

    printf("\n--- Class Result ---\n"); // header
    printf("Average Score: %.2f\n", avg); // output

    free(list); // cleanup
    return 0; // ok
}
