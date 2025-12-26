#include <stdio.h>

#define MAX_ROOMS 20
#define STUDENTS_PER_ROOM 10

struct Student {
    char name[20];
    int age;
    char gender;
    float gpa;
};

/* ===== Prototype ตามโจทย์ ===== */
void GetStudent(struct Student room[][STUDENTS_PER_ROOM], int *roomCount);

/* =============================== */

int main() {
    struct Student classroom[MAX_ROOMS][STUDENTS_PER_ROOM];
    int nRoom = 0;

    /* เรียกใช้ฟังก์ชัน */
    GetStudent(classroom, &nRoom);

    return 0;
}

/* ========= Function Definition ========= */
void GetStudent(struct Student room[][STUDENTS_PER_ROOM], int *roomCount) {
    int r, s;

    printf("Enter number of classrooms: ");
    if (scanf("%d", roomCount) != 1) {
        return; // กัน input พัง
    }

    if (*roomCount < 1 || *roomCount > MAX_ROOMS) {
        printf("Invalid room count\n");
        return;
    }

    for (r = 0; r < *roomCount; r++) {
        printf("\n=== Room %d ===\n", r + 1);

        for (s = 0; s < STUDENTS_PER_ROOM; s++) {
            printf("Student %d -> Name Age Gender GPA: ", s + 1);

            /* จุดสำคัญ: มี space หน้า %c */
            if (scanf("%19s %d %c %f",
                      room[r][s].name,
                      &room[r][s].age,
                      &room[r][s].gender,
                      &room[r][s].gpa) != 4) {
                return;
            }
        }
    }
}
