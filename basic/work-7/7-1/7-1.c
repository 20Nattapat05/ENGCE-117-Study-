#include <stdio.h>

int main()
{
    FILE *file;
    const char filename[] = "output_data.txt";
    int current_year = 2025;
    const char message[] = "Hello, C File Handling is easy.";

    file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("ERROR: Cannot create file %s\n", filename);
        return 1;
    }

    fprintf(file, "%s\nYear: %d\n", message, current_year);

    printf("\n--- FILE WRITING PROCESS ---\n");
    printf("Target file : %s\n", filename);
    printf("Writing data...\n");
    printf("Writing completed successfully.\n");

    printf("\n--- FILE OPERATION REPORT ---\n");
    printf("Status   : SUCCESS\n");
    printf("Filename : %s\n", filename);

    fclose(file);
    return 0;
}