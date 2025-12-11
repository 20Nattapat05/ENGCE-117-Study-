#include <stdio.h>
#include <string.h>

// Function prototype
void explode(char str1[], char splitter, char str2[][100], int *count);

int main() {
    char str1[100], splitter;
    char str2[10][100]; // Array to store split words
    int count = 0;

    // Call explode function
    explode(str1, splitter, str2, &count);

    return 0;
}

// Function to split string
void explode(char str1[], char splitter, char str2[][100], int *count) {
    // Get input string
    printf("Enter the string to be split: ");
    fgets(str1, sizeof(str1), stdin);
    str1[strcspn(str1, "\n")] = '\0';  // Remove newline character if exists

    // Get splitter character
    printf("Enter the splitter character: ");
    scanf("%c", &splitter);  // Read splitter

    // Convert the splitter to a string for strtok
    char delimiter[2] = {splitter, '\0'};  // Create a string with the splitter

    char *token;
    *count = 0;  // Reset word count

    // Split string by the splitter
    token = strtok(str1, delimiter);
    while (token != NULL) {
        strcpy(str2[*count], token);  // Store the token
        (*count)++;  // Increment word count
        token = strtok(NULL, delimiter);  // Get next token
    }

    // Print the split words and count
    for (int i = 0; i < *count; i++) {
        printf("str2[%d] = \"%s\"\n", i, str2[i]);
    }
    printf("count = %d\n", *count);
}
