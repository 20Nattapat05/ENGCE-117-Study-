#include <stdio.h>

// upper?
static int is_upper(char c) { return (c >= 'A' && c <= 'Z'); }

// lower?
static int is_lower(char c) { return (c >= 'a' && c <= 'z'); }

// digit?
static int is_digit(char c) { return (c >= '0' && c <= '9'); }

int main(void) {
    char text[101];   // input
    char *p = NULL;   // walker

    int upper = 0; // count U
    int lower = 0; // count L
    int digit = 0; // count D
    int other = 0; // count O

    if (scanf("%100s", text) != 1) return 1; // bad input

    // traverse
    for (p = text; *p != '\0'; ++p) {
        if (is_upper(*p))      ++upper; // U++
        else if (is_lower(*p)) ++lower; // L++
        else if (is_digit(*p)) ++digit; // D++
        else                   ++other; // O++
    }

    printf("Uppercase: %d\n", upper);          // print U
    printf("Lowercase: %d\n", lower);          // print L
    printf("Digits: %d\n", digit);             // print D
    printf("Special/other: %d\n", other);      // print O

    return 0; // ok
}
