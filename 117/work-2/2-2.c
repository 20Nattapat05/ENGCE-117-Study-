#include <stdio.h>
#include <string.h>
#include <stdlib.h>  // สำหรับ malloc

// Function prototype
void reverse(char str1[], char *str2);

int main() {
    char text[50];  // Input string
    char *out;      // Pointer to output string

    // Get user input
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);  // Read user input
    
    // Remove newline character
    text[strcspn(text, "\n")] = '\0';

    // Allocate memory for out
    out = (char *)malloc(strlen(text) + 1);  // +1 for the null terminator

    if (out == NULL) {
        printf("Memory allocation failed\n");
        return 1;  // Exit if memory allocation fails
    }

    reverse(text, out);  // Reverse the string

    // Free the allocated memory after usage
    free(out);

    return 0;
}

// Function to reverse the string
void reverse(char str1[], char *str2) {
    int len = strlen(str1);  // Length of input string
    int j = 0;
    
    // Reverse the string
    for (int i = len - 1; i >= 0; i--) {
        str2[j++] = str1[i];
    }
    str2[j] = '\0';  // Null-terminate the reversed string

    // Output the reversed string
    printf("Reversed String: %s\n", str2);
}
