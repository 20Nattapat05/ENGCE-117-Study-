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
void setNode(Node *p, const char *name, int age, char sex, float gpa);
void jump(Node ***ppp);

int main(void) {
    Node *head = NULL;
    Node **cursor = NULL;

    // build nodes
    head = malloc(sizeof(Node));
    setNode(head, "one", 6, 'M', 3.11f);

    head->next = malloc(sizeof(Node));
    setNode(head->next, "two", 8, 'F', 3.22f);

    head->next->next = malloc(sizeof(Node));
    setNode(head->next->next, "three", 10, 'M', 3.33f);

    head->next->next->next = malloc(sizeof(Node));
    setNode(head->next->next->next, "four", 12, 'F', 3.44f);

    cursor = &head;  // pointer to pointer

    printf("Before jump: %s\n", (*cursor)->name);

    // use triple pointer
    jump(&cursor);

    printf("After jump:  %s\n", (*cursor)->name);

    // free memory
    Node *tmp = head;
    while (tmp) {
        Node *next = tmp->next;
        free(tmp);
        tmp = next;
    }

    return 0;
}

// fill node fields
void setNode(Node *p, const char *name, int age, char sex, float gpa) {
    strcpy(p->name, name);
    p->age = age;
    p->sex = sex;
    p->gpa = gpa;
    p->next = NULL;
}

// move cursor via triple pointer
void jump(Node ***ppp) {
    if (**ppp && (**ppp)->next) {
        **ppp = (**ppp)->next;
    }
}
