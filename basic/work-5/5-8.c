#include <stdio.h>

typedef struct {
    int id;
    int m;
    int s;
    int e;
    int total;
} Student;

// prototypes
char grade(int total);
void avgScore(int total, float *pavg);

int main(void) {
    Student st;
    char g;
    float avg;

    printf("ID: ");
    scanf("%d", &st.id);

    printf("Math: ");
    scanf("%d", &st.m);

    printf("Science: ");
    scanf("%d", &st.s);

    printf("English: ");
    scanf("%d", &st.e);

    // compute total
    st.total = st.m + st.s + st.e;

    // compute grade
    g = grade(st.total);

    // compute average (by pointer)
    avgScore(st.total, &avg);

    // report
    printf("\n=== STUDENT REPORT ===\n");
    printf("ID: %d\n", st.id);
    printf("Scores -> M:%d S:%d E:%d\n", st.m, st.s, st.e);
    printf("Total: %d\n", st.total);
    printf("Average: %.2f\n", avg);
    printf("Grade: %c\n", g);

    return 0;
}

// decide letter grade
char grade(int total) {
    if (total >= 250)
        return 'A';
    else if (total >= 200)
        return 'B';
    else
        return 'C';
}

// write average via pointer
void avgScore(int total, float *pavg) {
    *pavg = (float)total / 3.0f;
}
