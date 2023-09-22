//Write a c program to find maximum of each row, maximum of each column, minimum of each row, minimum of each column, and highest element and lowest element in a user input matrix//
#include <stdio.h>

int main() {
    int m, n, i, j;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    printf("Enter the elements of the matrix: \n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Finding maximum and minimum elements of each row
    printf("\nMaximum elements of each row:\n");
    for (i = 0; i < m; i++) {
        int max = matrix[i][0];
        for (j = 1; j < n; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        printf("Row %d: %d\n", i+1, max);

        int min = matrix[i][0];
        for (j = 1; j < n; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        printf("Row %d: %d\n", i+1, min);
    }

    // Finding maximum and minimum elements of each column
    printf("\nMaximum elements of each column:\n");
    for (j = 0; j < n; j++) {
        int max = matrix[0][j];
        for (i = 1; i < m; i++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
        printf("Column %d: %d\n", j+1, max);

        int min = matrix[0][j];
        for (i = 1; i < m; i++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
        printf("Column %d: %d\n", j+1, min);
    }

    // Finding the highest and lowest element in the matrix
    int highest = matrix[0][0];
    int lowest = matrix[0][0];
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            if (matrix[i][j] > highest) {
                highest = matrix[i][j];
            }
            if (matrix[i][j] < lowest) {
                lowest = matrix[i][j];
            }
        }
    }
    printf("\nHighest element in the matrix: %d\n", highest);
    printf("Lowest element in the matrix: %d\n", lowest);
    return 0;
}