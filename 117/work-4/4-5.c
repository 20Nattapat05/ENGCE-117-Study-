#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct Student *next;
} Student;

// prototypes
Student *makeNode(const char *name, int age, char sex, float gpa);
void step(Student **pp);

int main(void) {
    Student *head = NULL;
    Student **walker = NULL;

    // build list
    head = makeNode("one", 6, 'M', 3.11f);
    head->next = makeNode("two", 8, 'F', 3.22f);
    head->next->next = makeNode("three", 10, 'M', 3.33f);
    head->next->next->next = makeNode("four", 12, 'F', 3.44f);

    walker = &head;   // pointer to pointer

    step(walker);     // move to next

    printf("Current student: %s\n", (*walker)->name);

    // free memory
    Student *tmp = head;
    while (tmp) {
        Student *next = tmp->next;
        free(tmp);
        tmp = next;
    }

    return 0;
}

// allocate + initialize node
Student *makeNode(const char *name, int age, char sex, float gpa) {
    Student *n = malloc(sizeof(Student));
    strcpy(n->name, name);
    n->age = age;
    n->sex = sex;
    n->gpa = gpa;
    n->next = NULL;
    return n;
}

// move pointer via double pointer
void step(Student **pp) {
    if (*pp && (*pp)->next) {
        *pp = (*pp)->next;
    }
}
