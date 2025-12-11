#include <stdio.h>
#include <string.h>

// Function prototype for reverse
char* reverse(char str1[]);

int main() {
    char text[50];  // Declare an array to hold the user input
    char *out;

    // Ask the user for input
    printf("Enter a string: ");
    fgets(text, sizeof(text), stdin);  // Use fgets to safely read input with spaces

    // Remove the newline character added by fgets, if any
    text[strcspn(text, "\n")] = '\0';

    // Call the reverse function to reverse the string
    out = reverse(text);

    // Print the original string and the reversed string
    printf("Original: %s\n", text);
    printf("Reversed: %s\n", out);

    return 0;
}

// Function to reverse the string
char* reverse(char str1[]) {
    static char str2[50];  // Use static to ensure str2 stays valid after the function returns
    int len = strlen(str1);  // Get the length of str1
    int j = 0;
    
    // Loop through str1 from the end to the beginning and copy to str2
    for (int i = len - 1; i >= 0; i--) {
        str2[j++] = str1[i];
    }
    
    str2[j] = '\0';  // Add null terminator to the end of str2
    
    return str2;  // Return the reversed string
}
