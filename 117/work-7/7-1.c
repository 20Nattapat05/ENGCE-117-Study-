#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Node structure */
struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

/* Linked list structure */
struct LinkedList {
    struct studentNode *start;
    struct studentNode *now;
};

/* Initialize list */
void initList(struct LinkedList *list) {
    list->start = NULL;
    list->now = NULL;
}

/* Insert node at end */
void InsNode(struct LinkedList *list, char name[], int age, char sex, float gpa) {

    struct studentNode *newNode =
        (struct studentNode*)malloc(sizeof(struct studentNode));

    if (newNode == NULL) return;   // memory check

    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;

    /* pointer used to find last node */
    struct studentNode **ptr = &(list->start);

    while (*ptr != NULL)
        ptr = &((*ptr)->next);

    *ptr = newNode;
}

/* Delete first node */
void DelNode(struct LinkedList *list) {

    if (list->start == NULL)
        return;   // empty list

    struct studentNode *temp = list->start;
    list->start = temp->next;

    free(temp);
}

/* Move pointer to next node */
void GoNext(struct LinkedList *list) {

    if (list->now == NULL)
        list->now = list->start;   // start at first node
    else
        list->now = list->now->next;
}

int main() {

    struct LinkedList listA, listB;
    struct LinkedList *listC;

    initList(&listA);
    initList(&listB);

    /* ----- listA ----- */
    InsNode(&listA, "one", 1, 'A', 1.1);
    InsNode(&listA, "two", 2, 'B', 2.2);
    InsNode(&listA, "three", 3, 'C', 3.3);

    GoNext(&listA);
    GoNext(&listA);

    printf("%s %d %c %.2f\n",
           listA.now->name,
           listA.now->age,
           listA.now->sex,
           listA.now->gpa);

    /* ----- listB ----- */
    InsNode(&listB, "four", 4, 'D', 4.4);
    InsNode(&listB, "five", 5, 'E', 5.5);
    InsNode(&listB, "six", 6, 'F', 6.6);

    DelNode(&listB);

    printf("%s %s\n",
           listB.start->next->name,
           listB.start->name);

    /* ----- pointer test ----- */
    listC = &listA;

    printf("%s %d %c %.2f\n",
           listC->start->name,
           listC->start->age,
           listC->start->sex,
           listC->start->gpa);

    listC = &listB;

    printf("%s %s\n",
           listC->start->next->name,
           listC->start->name);

    return 0;
}