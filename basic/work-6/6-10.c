#include <stdio.h>

/* store student info */
typedef struct {
    int id;
    int mark;
    char result;
} Student;

void printMenu();
void assignGrade(Student *st);

int main()
{
    Student st = {0, 0, 'U'};
    int menu = 0;

    do {
        printMenu();
        scanf("%d", &menu);

        if(menu == 1)
        {
            printf("Student ID: ");
            scanf("%d", &st.id);

            printf("Student Score: ");
            scanf("%d", &st.mark);

            assignGrade(&st);   // calculate grade
            printf("Record saved.\n");
        }
        else if(menu == 2)
        {
            if(st.id == 0)
            {
                printf("No data found.\n");
            }
            else
            {
                printf("\n--- REPORT ---\n");
                printf("ID    : %d\n", st.id);
                printf("Score : %d\n", st.mark);
                printf("Grade : %c\n", st.result);
            }
        }
        else if(menu == 3)
        {
            printf("Program closed.\n");
        }
        else
        {
            printf("Wrong menu. Try again.\n");
        }

    } while(menu != 3);

    return 0;
}

/* show menu */
void printMenu()
{
    printf("\n==== STUDENT MENU ====\n");
    printf("1. Add / Edit Student\n");
    printf("2. Show Report\n");
    printf("3. Exit\n");
    printf("Select: ");
}

/* set grade */
void assignGrade(Student *st)
{
    int s = st->mark;

    if(s >= 80)      st->result = 'A';
    else if(s >= 70) st->result = 'B';
    else if(s >= 60) st->result = 'C';
    else if(s >= 50) st->result = 'D';
    else             st->result = 'F';
}
