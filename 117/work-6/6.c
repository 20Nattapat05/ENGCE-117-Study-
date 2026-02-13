#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode
{
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

/* prototypes */
struct studentNode *AddNode(struct studentNode **start,
                            char name[], int age, char sex, float gpa);
void InsNode(struct studentNode *now,
             char name[], int age, char sex, float gpa);
void GoBack(struct studentNode **now);
void DelNode(struct studentNode *now);
void ShowAll(struct studentNode *walk);

/* ---------------- MAIN ---------------- */
int main()
{
    struct studentNode *start, *now;
    start = NULL;

    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);

    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(start);

    GoBack(&now);
    DelNode(now);
    ShowAll(start);
    DelNode(now);
    ShowAll(start);
    DelNode(now);
    ShowAll(start);

    return 0;
}

/* ---------------- FUNCTIONS ---------------- */

/* Add to end */
struct studentNode *AddNode(struct studentNode **start,
                            char name[], int age, char sex, float gpa)
{

    struct studentNode *newNode, *temp;

    newNode = (struct studentNode *)malloc(sizeof(struct studentNode));

    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;
    newNode->back = NULL;

    /* if empty */
    if (*start == NULL)
    {
        *start = newNode;
        return newNode;
    }

    /* walk to end */
    temp = *start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode; // link next
    newNode->back = temp; // link back

    return newNode; // return new
}

/* Insert before now */
void InsNode(struct studentNode *now,
             char name[], int age, char sex, float gpa)
{

    if (now == NULL)
        return;

    struct studentNode *newNode;

    newNode = (struct studentNode *)malloc(sizeof(struct studentNode));

    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = now;       // link forward
    newNode->back = now->back; // link back

    if (now->back != NULL)
        now->back->next = newNode;

    now->back = newNode; // update now back
}

/* Move back */
void GoBack(struct studentNode **now)
{
    if (*now == NULL)
        return;
    if ((*now)->back != NULL)
        *now = (*now)->back;
}

/* Delete now */
void DelNode(struct studentNode *now)
{
    if (now == NULL)
        return;

    struct studentNode *prev = now->back;
    struct studentNode *next = now->next;

    if (prev != NULL)
        prev->next = next;

    if (next != NULL)
        next->back = prev;

    free(now); // free memory
}

/* Show all names */
void ShowAll(struct studentNode *walk)
{
    while (walk != NULL)
    {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}