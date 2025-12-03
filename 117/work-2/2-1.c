#include <stdio.h>
#include <string.h>

// Function prototype
void reverse(char str1[], char str2[]);

int main() {
    char text[50], out[50];  // Input and output strings

    // Get user input
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);  // Read user input
    
    // Remove newline character
    text[strcspn(text, "\n")] = '\0';

    reverse(text, out);  // Reverse the string
    
    return 0;
}

// Function to reverse the string
void reverse(char str1[], char str2[]) {
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
