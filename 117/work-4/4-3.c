#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct StudentNode {
    char name[20];
    int age;
    char gender;
    float gpa;
    struct StudentNode *next;
} StudentNode;

// prototypes
void setupNode(StudentNode *s, const char *n, int a, char g, float gp);
void stepNext(StudentNode *cursor);
void showNode(StudentNode *cursor);

int main(void) {
    StudentNode *head = NULL;
    StudentNode *current = NULL;

    // build list manually
    head = malloc(sizeof(StudentNode));
    setupNode(head, "one", 6, 'M', 3.11f);

    head->next = malloc(sizeof(StudentNode));
    setupNode(head->next, "two", 8, 'F', 3.22f);

    head->next->next = malloc(sizeof(StudentNode));
    setupNode(head->next->next, "three", 10, 'M', 3.33f);

    head->next->next->next = malloc(sizeof(StudentNode));
    setupNode(head->next->next->next, "four", 12, 'F', 3.44f);

    current = head;          // start at first node

    // try to move (pass
