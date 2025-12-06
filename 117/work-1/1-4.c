#include <stdio.h>

// Function to get and set array elements
int GetSet( int Array[] ) ;

int main() {
    int data[777], num = 0 ;
    num = GetSet( data ) ;
    return 0 ;
}

// Get and set function definition
int GetSet( int Array[] ) {
    int num = 0 ;

    printf( "Enter the number of Elements: " ) ;
    scanf( "%d", &num ) ;

    printf( "Enter the Elements: " ) ;
    for ( int i = 0 ; i < num ; i++ ) {
        scanf( "%d", &Array[i] ) ;  // Store input directly into the array
    }

    printf( "Number of Elements: %d\n", num ) ;
    for ( int i = 0 ; i < num ; i++ ) {
        printf( "%d ", Array[i] ) ;  // Print the array elements
    }

    return 0 ;
}
