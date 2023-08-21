#include <stdio.h>
#include <stdbool.h>

#define N 4

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < row; i++) {
        if (board[i][col])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j])
            return false;
    }

    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j])
            return false;
    }

    return true;
}

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void solveNQueensUtil(int board[N][N], int row) {
    if (row == N) {
        printSolution(board);
        return;
    }

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            solveNQueensUtil(board, row + 1);
            board[row][col] = 0; // Backtrack
        }
    }
}

void solveNQueens() {
    int board[N][N] = {0};
    solveNQueensUtil(board, 0);
}

int main() {
    solveNQueens();
    return 0;
}
