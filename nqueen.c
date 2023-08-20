#include <stdio.h>
#include <stdbool.h>

#define N 8 // Number of queens and the size of the chessboard

bool isSafe(int board[N][N], int row, int col)
{
    // Check if there is a queen in the same column
    for (int i = 0; i < row; i++)
    {
        if (board[i][col])
            return false;
    }

    // Check upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
            return false;
    }

    // Check upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++)
    {
        if (board[i][j])
            return false;
    }

    return true;
}

bool solveNQueensUtil(int board[N][N], int row)
{
    if (row == N)
    {
        // All queens are placed successfully
        return true;
    }

    for (int col = 0; col < N; col++)
    {
        if (isSafe(board, row, col))
        {
            board[row][col] = 1; // Place the queen

            if (solveNQueensUtil(board, row + 1))
            {
                return true;
            }

            // If placing queen in board[row][col] doesn't lead to a solution, backtrack
            board[row][col] = 0;
        }
    }

    // No suitable column found for this row, backtrack
    return false;
}

void solveNQueens()
{
    int board[N][N] = {0};

    if (!solveNQueensUtil(board, 0))
    {
        printf("Solution does not exist.\n");
        return;
    }

    // Print the solution
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    solveNQueens();
    return 0;
}
