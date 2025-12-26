#include <stdio.h>

// data struct
typedef struct
{
    char name[20];
    int age;
    char sex;
    float gpa;
} Student;

// upgrade copy
static Student upgrade(Student s)
{
    if (s.sex == 'M')                  // male?
        s.gpa = s.gpa + s.gpa * 0.10f; // +10%
    else
        s.gpa = s.gpa + s.gpa * 0.20f; // +20%

    printf("%.2f\n", s.gpa); // print 2
    return s;                // return copy
}

int main(void)
{
    Student boy; // one

    boy.sex = 'M';   // set sex
    boy.gpa = 3.00f; // set gpa

    printf("%.2f\n", boy.gpa); // print 1

    boy = upgrade(boy); // call by value

    printf("%.2f\n", boy.gpa); // print 3

    return 0; // ok
}
