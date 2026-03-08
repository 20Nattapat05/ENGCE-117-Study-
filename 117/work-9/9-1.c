#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Student structure */
struct student {
    char name[20];
    int age;
    char sex;
    float gpa;
};

/* Add student data */
void addData() {

    FILE *fp = fopen("student.dat", "ab");
    struct student s;

    if (fp == NULL) return;   // file check

    printf("Name: "); scanf("%s", s.name);
    printf("Age: "); scanf("%d", &s.age);
    printf("Sex: "); scanf(" %c", &s.sex);
    printf("GPA: "); scanf("%f", &s.gpa);

    fwrite(&s, sizeof(struct student), 1, fp);

    fclose(fp);
}

/* Show all students */
void showAll() {

    FILE *fp = fopen("student.dat", "rb");
    struct student s;

    if (fp == NULL) return;   // file check

    while (fread(&s, sizeof(struct student), 1, fp)) {

        printf("%s %d %c %.2f\n",
               s.name,
               s.age,
               s.sex,
               s.gpa);
    }

    fclose(fp);
}

/* Search student by name */
void findData() {

    FILE *fp = fopen("student.dat", "rb");
    struct student s;
    char search[20];
    int found = 0;

    if (fp == NULL) return;

    printf("Search name: ");
    scanf("%s", search);

    while (fread(&s, sizeof(struct student), 1, fp)) {

        if (strcmp(s.name, search) == 0) {

            printf("Found: %s %d %c %.2f\n",
                   s.name, s.age, s.sex, s.gpa);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Not found!\n");

    fclose(fp);
}

/* Delete student */
void deleteData() {

    FILE *fp = fopen("student.dat", "rb");
    FILE *temp = fopen("temp.dat", "wb");

    struct student s;
    char delname[20];
    int found = 0;

    if (fp == NULL || temp == NULL) return;

    printf("Delete name: ");
    scanf("%s", delname);

    while (fread(&s, sizeof(struct student), 1, fp)) {

        if (strcmp(s.name, delname) != 0)
            fwrite(&s, sizeof(struct student), 1, temp);
        else
            found = 1;
    }

    fclose(fp);
    fclose(temp);

    remove("student.dat");
    rename("temp.dat", "student.dat");

    if (found)
        printf("Deleted successfully\n");
    else
        printf("Not found\n");
}

/* Edit student data */
void editData() {

    FILE *fp = fopen("student.dat", "rb+");
    struct student s;

    char editname[20];
    int found = 0;

    if (fp == NULL) return;

    printf("Edit name: ");
    scanf("%s", editname);

    while (fread(&s, sizeof(struct student), 1, fp)) {

        if (strcmp(s.name, editname) == 0) {

            printf("New age: "); scanf("%d", &s.age);
            printf("New sex: "); scanf(" %c", &s.sex);
            printf("New GPA: "); scanf("%f", &s.gpa);

            /* move pointer back to rewrite data */
            fseek(fp, -sizeof(struct student), SEEK_CUR);

            fwrite(&s, sizeof(struct student), 1, fp);

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Not found!\n");

    fclose(fp);
}

int main() {

    int menu;

    do {

        printf("\nMenu\n");
        printf("1. Add\n");
        printf("2. Edit\n");
        printf("3. Delete\n");
        printf("4. Find\n");
        printf("5. Show All\n");
        printf("0. Exit\n");

        printf("Select: ");
        scanf("%d", &menu);

        switch(menu) {

            case 1:
                addData();
                break;

            case 2:
                editData();
                break;

            case 3:
                deleteData();
                break;

            case 4:
                findData();
                break;

            case 5:
                showAll();
                break;
        }

    } while(menu != 0);

    return 0;
}