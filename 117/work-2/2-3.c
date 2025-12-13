#include <stdio.h>
#include <string.h>

void explode(char str1[], char splitter, char str2[][100], int *count);

int main(void)
{
    char str1[100], splitter;
    char str2[10][100];
    int count = 0;

    explode(str1, splitter, str2, &count);
    return 0;
}

void explode(char str1[], char splitter, char str2[][100], int *count)
{
    printf("Enter the string to be split: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = '\0';

    printf("Enter the splitter character: ");
    scanf("%c", &splitter);

    char delimiter[2] = { splitter, '\0' };
    char *token;
    *count = 0;

    token = strtok(str1, delimiter);
    while (token != NULL)
    {
        strcpy(str2[*count], token);
        (*count)++;
        token = strtok(NULL, delimiter);
    }

    for (int i = 0; i < *count; i++)
        printf("str2[%d] = \"%s\"\n", i, str2[i]);

    printf("count = %d\n", *count);
}
