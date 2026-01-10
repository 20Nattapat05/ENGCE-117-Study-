#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20

struct studentNode
{
    char name[NAME_LEN];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

/* ===== PROTOTYPE ===== */
void ShowAll(struct studentNode **walk);
void InsNode(struct studentNode **pos, char *name, int age, char sex, float gpa);
void DelNode(struct studentNode **pos);
void GoNext(struct studentNode ***pos);

/* ===================== MAIN ===================== */
int main()
{
    struct studentNode *start = NULL;
    struct studentNode **now = &start;

    InsNode(now, "one", 6, 'M', 3.11); // แทรกตัวแรก
    ShowAll(&start);

    InsNode(now, "two", 8, 'F', 3.22); // แทรกก่อน one
    ShowAll(&start);

    GoNext(&now); // เลื่อนไปที่ one
    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(&start);

    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(&start);

    GoNext(&now); // เลื่อนไปที่ three
    DelNode(now); // ลบ three
    ShowAll(&start);

    return 0;
}

/* ===================== FUNCTIONS ===================== */

// แทรกโหนดใหม่ที่ตำแหน่ง pos
void InsNode(struct studentNode **pos, char *name, int age, char sex, float gpa)
{
    struct studentNode *newNode = malloc(sizeof(struct studentNode));
    if (newNode == NULL)
        return; // ป้องกัน malloc fail

    strncpy(newNode->name, name, NAME_LEN);
    newNode->name[NAME_LEN - 1] = '\0';
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = *pos;
    *pos = newNode;
}

// ลบโหนดที่ pos ชี้อยู่
void DelNode(struct studentNode **pos)
{
    if (*pos == NULL)
        return;

    struct studentNode *temp = *pos;
    *pos = temp->next;
    free(temp);
}

// เลื่อน pos ไปยัง next node
void GoNext(struct studentNode ***pos)
{
    if (**pos != NULL)
    {
        *pos = &((**pos)->next);
    }
}

// แสดงชื่อทุกโหนด
void ShowAll(struct studentNode **walk)
{
    struct studentNode *ptr = *walk;
    while (ptr != NULL)
    {
        printf("%s ", ptr->name);
        ptr = ptr->next;
    }
    printf("\n");
}
