#include <stdio.h>

#define MAX_ROOMS 20
#define STUDENTS_PER_ROOM 10

struct StudentInfo {
    char name[20];
    int age;
    char gender;
    float gpa;
};

/* Function prototype */
void inputStudents(struct StudentInfo list[][STUDENTS_PER_ROOM], int *totalRooms);

int main() {
    struct StudentInfo classroom[MAX_ROOMS][STUDENTS_PER_ROOM];
    int roomCount = 0;

    /* Get student data */
    inputStudents(classroom, &roomCount);

    return 0;
}

/* Function definition */
void inputStudents(struct StudentInfo list[][STUDENTS_PER_ROOM], int *totalRooms) {
    int r, s;

    /* Read number of rooms */
    printf("Enter number of classrooms: ");
    scanf("%d", totalRooms);

    /* Loop through rooms */
    for (r = 0; r < *totalRooms; r++) {
        printf("\n=== Room %d ===\n", r + 1);

        /* Loop through students */
        for (s = 0; s < STUDENTS_PER_ROOM; s++) {
            printf("Student %d -> Name Age Gender GPA: ", s + 1);
            scanf("%s %d %c %f",
                  list[r][s].name,
                  &list[r][s].age,
                  &list[r][s].gender,
                  &list[r][s].gpa);
        }
    }
}