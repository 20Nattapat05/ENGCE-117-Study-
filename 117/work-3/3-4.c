#include <stdio.h>

#define ROOM_LIMIT 20 // max rooms
#define PER_ROOM 10   // max students per room

typedef struct
{
    char name[20];
    int age;
    char gender;
    float gpa;
} Student;

// function prototype
void readData(Student arr[][PER_ROOM], int *rooms);

int main(void)
{
    Student data[ROOM_LIMIT][PER_ROOM];
    int roomTotal = 0;

    readData(data, &roomTotal); // get input

    return 0;
}

void readData(Student arr[][PER_ROOM], int *rooms)
{
    int i, j;

    printf("How many rooms: ");
    scanf("%d", rooms);

    for (i = 0; i < *rooms; i++)
    {
        printf("\n-- Room %d --\n", i + 1);

        for (j = 0; j < PER_ROOM; j++)
        {
            printf("Student %d (Name Age Gender GPA): ", j + 1);
            scanf("%19s %d %c %f",
                  arr[i][j].name,
                  &arr[i][j].age,
                  &arr[i][j].gender,
                  &arr[i][j].gpa);
        }
    }
}
