#include <stdio.h>

int main() {
    int score;

    scanf("%d", &score);

    if (score >= 80) {
        printf("Grade A");
    }
    else if (score >= 70 && score < 80) {
        printf("Grade B");
    }
    else if (score >= 60 && score < 70) {
        printf("Grade C");
    }
    else if (score >= 50 && score < 60) {
        printf("Grade D");
    }
    else if (score < 50) {
        printf("Grade F");
    }

    return 0;
}
