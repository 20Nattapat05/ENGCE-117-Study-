#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct Node *next;
} Node;

// prototypes
Node *newNode(const char *n, int a, char s, float g);
void advance(Node **pp);

int main(void) {
    Node *head = NULL;
    Node *cursor = NULL;

    // build list
    head = newNode("one", 6, 'M', 3.11f);
    head->next = newNode("two", 8, 'F', 3.22f);
    head->next->next = newNode("three", 10, 'M', 3.33f);

    cursor = head;       // start at first

    advance(&cursor);    // move to next

    printf("Current student: %s\n", cursor->name);

    // free list
    Node *tmp = head;
    while (tmp) {
        Node *next = tmp->next;
        free(tmp);
        tmp = next;
    }

    return 0;
}

// allocate + fill node
Node *newNode(const char *n, int a, char s, float g) {
    Node *p = malloc(sizeof(Node));
    strcpy(p->name, n);
    p->age = a;
    p->sex = s;
    p->gpa = g;
    p->next = NULL;
    return p;
}

// move pointer via double pointer
void advance(Node **pp) {
    if (*pp && (*pp)->next) {
        *pp = (*pp)->next;
    }
}
