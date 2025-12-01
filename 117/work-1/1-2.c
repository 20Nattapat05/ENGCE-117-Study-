#include <stdio.h>
#include <stdlib.h>

void GetSet(int **data, int *num);

int main() {
    int *data, num;

    GetSet(&data, &num); // Get data and print members

    return 0;
}

void GetSet(int **data, int *num) {
    printf("Number of members: ");
    scanf("%d", num);  // Must be fixed to &(*num)

    *data = malloc(*num * sizeof(int)); // Allocate memory for the array

    printf("Enter values one by one:\n");
    for(int i = 0; i < *num; i++){
        printf("Member %d: ", i+1);
        scanf("%d", &(*data)[i]); // Get value of each member
    }

    printf("\nMembers in the set received:\n");
    for(int i = 0; i < *num; i++){
        printf("%d ", (*data)[i]); // Print all members
    }
    printf("\n");
}