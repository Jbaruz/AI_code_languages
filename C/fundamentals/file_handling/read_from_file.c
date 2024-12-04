// Read from a file programming on C
// Author: JBA
// Date: 03-12-2024

// Include Necessary Library <--
#include <stdio.h> // This library provides functions for working with files, input/output operations

// Start the main Function <--
// The program begins its execution here.
int main() {
    // Open a File <--
    // FILE *file: Declares a pointer to a FILE structure to handle file operations.
    // fopen: Opens the file named data.txt in read mode (r).
    // "r": Means the program can only read from the file, not write or modify it.
    // The result of fopen is stored in the pointer file.
    FILE * file = fopen("data.txt", "r");

    // Check if the File Opened Successfully <--
    // file == NULL: Checks if fopen failed to open the file
    // If the file cannot be opened, the program prints an error message and exits with return 1.
    if (file == NULL) {
        printf("Error: Cannot open file\n");
        return 1;
    }

    // Read and Print the File Line by Line <--
    // char line[100];: Declares an array to store each line of text from the file, 
    // with a maximum length of 100 characters.
    // fgets:
    // Reads one line of text at a time from the file into the line array.
    // Stops reading when a newline (\n) is encountered or the array limit (100) is reached.
    // Returns NULL when there are no more lines to read, which ends the loop.
    // printf("%s", line);: Prints the line to the console
    char line[100];
    while (fgets(line, sizeof(line), file)) {
        printf("%s", line);
    }

    // Close the File <--
    // Frees up resources used by the file. 
    // Always close files after you’re done with them to prevent resource leaks.
    fclose(file);

    // End the Program <--
    return 0;
}