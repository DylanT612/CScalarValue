// I certify, that this computer program submitted by me is all of my own work.
// Signed: Dylan Theis 5/18/2024

// Author: Dylan Theis
// Date: Summer 2024
// Class: CSC330
// Project: 5x5 scalar board
// Description: Accepts a 5 x 5 matrix of integers from a file, asks the user for a scalar integer, multiplies them together, and outputs the resulting matrix

// Standard library input/output header file and allows printf scanf
#include <stdio.h>

// Entry point of program
int main() {
    // Declare variables filename, multiplier, file, number, and count
    char filename[100];
    int multiplier;
    FILE *file;
    int number;
    int count = 0;

    // Prompt the user for the file to read
    printf("What file would you like to load a 5 x 5 matrix from? ");
    scanf("%s", filename);

    // Open the file in read only of print error
    file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file");
        // 1 indicates an error
        return 1;
    }

    // Prompt the user for the multiplier
    printf("Enter the scalar value: ");
    scanf("%d", &multiplier);

    // Print results header
    printf("Results:\n");

    // Read the numbers from the file, multiply by the given value, and print the results
    // fscanf reads int from file by pointer 'file' and stores it in the variable 'number'and returns 1 if successful
    while (fscanf(file, "%d", &number) == 1) {
        // Print the read number * multiplier
        printf("%d ", number * multiplier);
        // Increase count by 1
        count++;
        // Every 5 integers go to the next line
        if (count % 5 == 0) {
            printf("\n");
        }
    }

    // Close the file
    fclose(file);

    // Indicate exit status
    return 0;
}
