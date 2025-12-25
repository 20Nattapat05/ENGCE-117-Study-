#include <stdio.h>

// data struct
typedef struct {
    char name[20];
    int age;
    char sex;
    float gpa;
} Student;

// upgrade GPA
static void upgrade(Student *s) {
    if (s->sex == 'M')          // male?
        s->gpa *= 1.10f;        // +10%
    else                        // female/other
        s->gpa *= 1.20f;        // +20%
}

int main(void) {
    Student aboy;   // one student

    aboy.sex = 'M';   // set sex
    aboy.gpa = 3.00f; // set gpa

    upgrade(&aboy);   // apply

    printf("%.2f", aboy.gpa); // print
    return 0; // ok
}
