#include <stdio.h>

int main(void) {
    int N, i;
    int studentId, score, totalClasses, absentClasses;
    float attendancePercent;
    int passCount = 0, failCount = 0;

    if (scanf("%d", &N) != 1) return 1;

    for (i = 0; i < N; i++) {
        if (scanf("%d %d %d %d", &studentId, &score, &totalClasses, &absentClasses) != 4) {
            return 1;
        }

        if (totalClasses <= 0) {
            attendancePercent = 0.0f;  // กันหารศูนย์
        } else {
            attendancePercent = ((float)(totalClasses - absentClasses) / (float)totalClasses) * 100.0f;
        }

        int scoreOK = (score >= 50);
        int attendOK = (attendancePercent >= 75.0f);

        if (scoreOK && attendOK) {
            printf("Student %d: PASS\n", studentId);
            passCount++;
        } else {
            printf("Student %d: FAIL - ", studentId);

            if (!scoreOK && !attendOK) {
                printf("Both Score and Attendance\n");
            } else if (!scoreOK) {
                printf("Score\n");
            } else { // !attendOK
                printf("Attendance\n");
            }

            failCount++;
        }
    }

    printf("\n--- Summary ---\n");
    printf("Total PASS: %d\n", passCount);
    printf("Total FAIL: %d\n", failCount);

    return 0;
}
