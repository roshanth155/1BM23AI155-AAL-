#include <stdio.h>
#define N 8  // You can change N to the desired board size

// Function to print the solution
void printSolution(int board[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);  // Print board
        }
        printf("\n");
    }
}

// Function to check if a queen can be placed at board[row][col]
int isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check this column on upper side
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1) {
            return 0;
        }
    }

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1) {
            return 0;
        }
    }

    return 1;
}

// Function to solve the N-Queens problem using backtracking
int solveNQueens(int board[N][N], int row) {
    int col;  // Declare col outside the for loop

    // If all queens are placed, return true
    if (row >= N) {
        return 1;
    }

    // Try all columns in this row
    for (col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            // Place the queen
            board[row][col] = 1;

            // Recur to place the next queen
            if (solveNQueens(board, row + 1)) {
                return 1;
            }

            // If placing queen in board[row][col] doesn't lead to a solution,
            // backtrack and remove the queen
            board[row][col] = 0;
        }
    }

    // If the queen cannot be placed in any column in this row, return false
    return 0;
}

int main() {
    int board[N][N] = {0};  // Initialize board with all 0s

    if (solveNQueens(board, 0)) {
        printf("Solution:\n");
        printSolution(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
