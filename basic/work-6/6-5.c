#include <stdio.h>
#include <string.h>

// count vowels in string
void countVowels(const char *s, int *pv);

int main(void) {
    char line[100];
    int v = 0;

    printf("Input text: ");
    if (fgets(line, sizeof(line), stdin) == NULL)
        return 1;

    // trim newline
    line[strcspn(line, "\n")] = '\0';

    // do counting
    countVowels(line, &v);

    // report
    printf("\n=== VOWEL REPORT ===\n");
    printf("Text  : \"%s\"\n", line);
    printf("Vowel : %d\n", v);

    return 0;
}

void countVowels(const char *s, int *pv) {
    while (*s) {
        char c = *s;

        if (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
            c=='A'||c=='E'||c=='I'||c=='O'||c=='U')
            (*pv)++;        // increment via pointer

        s++;                // move pointer
    }
}
