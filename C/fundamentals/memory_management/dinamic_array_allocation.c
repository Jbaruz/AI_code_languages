// Dinamic array allocation programmin on C
// Author: JBA
// Date: 03-12-2024

#include <stdio.h> // For input and output functions (printf, scanf)
#include <stdlib.h> // For memory management functions (malloc, free)

//Declare main function <--
int main() {
    // Declare Variables <--
    int n, *arr; // n (store the # of elements in the array) *arr= (allocate memory for an int array)
    // Ask user for input <--
    printf("Enter number of elements: "); // Display the message for the user
    scanf("%d", &n); // Reads an integer value from the user and stores it in n.
    // Allocate memory dinamically <--
    arr = (int*)malloc(n * sizeof(int));
    // malloc: Allocates a block of memory  big enough to store n integers
    // n * sizeof(int): Calculates the total memory required for n integers
    // (int*): Casts the memory block to be used as an integer pointer

    // Check if Memory Allocation Failed <--
    // If malloc fails (e.g., insufficient memory), it returns NULL.
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;

    }
    // Assign Values to the Array <--
    // A loop runs from 0 to n-1.
    // For each index i, the program assigns the value i + 1 to arr[i].
    for (int i = 0; i < n; ++i){
        arr[i] = i + 1;
    }
    // Print Array Elements <--
    // Loops through the array and prints each value, followed by a space
    printf("Array elements: ");
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");

    // Free the Allocated Memory <--
    // Frees the memory that was dynamically allocated for the array.
    // Prevents memory leaks by ensuring the allocated memory is returned to the system.
    free(arr);
    // Return from the Program <--
    // Indicates successful completion of the program.
    return 0;
}
