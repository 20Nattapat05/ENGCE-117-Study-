#include <stdio.h>

int main(void) {
    int N, i;
    int studentId[100], score[100], totalClasses[100], absentClasses[100];
    float attendancePercent[100];
    int passCount = 0, failCount = 0;

    if (scanf("%d", &N) != 1) return 1;

    for (i = 0; i < N; i++) {
        if (scanf("%d %d %d %d", &studentId[i], &score[i], &totalClasses[i], &absentClasses[i]) != 4) {
            return 1;
        }

        if (totalClasses[i] <= 0)
            attendancePercent[i] = 0.0f;
        else
            attendancePercent[i] = ((float)(totalClasses[i] - absentClasses[i]) / totalClasses[i]) * 100.0f;
    }

    printf("\n--- Results ---\n");

    for (i = 0; i < N; i++) {
        int scoreOK = (score[i] >= 50);
        int attendOK = (attendancePercent[i] >= 75.0f);

        if (scoreOK && attendOK) {
            printf("Student %d: PASS\n", studentId[i]);
            passCount++;
        } else {
            printf("Student %d: FAIL - ", studentId[i]);
            if (!scoreOK && !attendOK)
                printf("Both Score and Attendance\n");
            else if (!scoreOK)
                printf("Score\n");
            else
                printf("Attendance\n");
            failCount++;
        }
    }

    printf("\n--- Summary ---\n");
    printf("Total PASS: %d\n", passCount);
    printf("Total FAIL: %d\n", failCount);

    return 0;
}
