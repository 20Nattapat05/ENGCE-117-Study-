#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LEN 20 // ความยาวชื่อสูงสุด

/* ===== STRUCT ===== */
struct studentNode
{
    char name[NAME_LEN];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

/* ===== PROTOTYPE ===== */
struct studentNode *AddNode(struct studentNode **start, char *name, int age, char sex, float gpa);
void InsNode(struct studentNode *now, char *name, int age, char sex, float gpa);
void DelNode(struct studentNode *now);
void ShowAll(struct studentNode *walk);

/* ===== MAIN ===== */
int main()
{
    struct studentNode *start = NULL, *now;

    now = AddNode(&start, "one", 6, 'M', 3.11);
    ShowAll(start);

    now = AddNode(&start, "two", 8, 'F', 3.22);
    ShowAll(start);

    InsNode(now, "three", 10, 'M', 3.33);
    ShowAll(start);

    InsNode(now, "four", 12, 'F', 3.44);
    ShowAll(start);

    DelNode(now);
    ShowAll(start);

    return 0;
}

/* ===== FUNCTIONS ===== */

// เพิ่มโหนดต่อท้ายลิสต์
struct studentNode *AddNode(struct studentNode **start, char *name, int age, char sex, float gpa)
{
    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    if (newNode == NULL)
        return NULL; // ตรวจสอบ malloc

    strncpy(newNode->name, name, NAME_LEN);
    newNode->name[NAME_LEN - 1] = '\0'; // ป้องกัน buffer overflow
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;
    newNode->next = NULL;

    // ถ้าลิสต์ว่าง ให้ newNode เป็นตัวแรก
    if (*start == NULL)
    {
        *start = newNode;
    }
    else
    {
        struct studentNode *walk = *start;
        while (walk->next != NULL)
            walk = walk->next;
        walk->next = newNode;
    }
    return newNode;
}

// แทรกโหนดหลัง now
void InsNode(struct studentNode *now, char *name, int age, char sex, float gpa)
{
    if (now == NULL)
        return;

    struct studentNode *newNode = (struct studentNode *)malloc(sizeof(struct studentNode));
    if (newNode == NULL)
        return;

    strncpy(newNode->name, name, NAME_LEN);
    newNode->name[NAME_LEN - 1] = '\0';
    newNode->age = age;
    newNode->sex = sex;
    newNode->gpa = gpa;

    newNode->next = now->next;
    now->next = newNode;
}

// ลบโหนดถัดจาก now
void DelNode(struct studentNode *now)
{
    if (now == NULL || now->next == NULL)
        return;

    struct studentNode *temp = now->next;
    now->next = temp->next;
    free(temp);
}

// แสดงรายชื่อทุกโหนด
void ShowAll(struct studentNode *walk)
{
    while (walk != NULL)
    {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}
