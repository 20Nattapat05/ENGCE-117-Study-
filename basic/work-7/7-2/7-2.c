#include <stdio.h>

#define COUNT 5

int main()
{
    FILE *file;
    const char filename[] = "input_data.csv";
    int values[COUNT];
    int sum = 0;

    file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("ERROR: Unable to open %s for reading.\n", filename);
        return 1;
    }

    if (fscanf(file, "%d,%d,%d,%d,%d",
               &values[0], &values[1], &values[2],
               &values[3], &values[4]) != COUNT)
    {
        printf("ERROR: Invalid file format.\n");
        fclose(file);
        return 1;
    }

    fclose(file);

    for (int i = 0; i < COUNT; i++)
    {
        sum += values[i];
    }

    printf("--- FILE READING PROCESS ---\n");
    printf("Source file: %s\n", filename);
    printf("Reading completed successfully.\n");

    printf("\n--- DATA ANALYSIS REPORT ---\n");
    printf("Data read: ");
    for (int i = 0; i < COUNT; i++)
    {
        printf("%d ", values[i]);
    }
    printf("\nTotal Sum: %d\n", sum);

    return 0;
}