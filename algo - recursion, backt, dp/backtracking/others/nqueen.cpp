#include "iostream"
using namespace std;
#define N 4
int board[N][N];

// refer n queen by javapoint/tutorial point for recursion tree diagram

// safe funtion is wrong (refer is safe of nqueenleetcode)
bool is_safe(int board[N][N], int row, int col)
{
    for (int i = 0; i < col; i++) // check whether there is queen in the left or not
        // check if the column had a queen before.
        for (int i = 0; i != row; ++i)
            if (board[i][col] == 1)
                return false;
    // check if the 45° diagonal had a queen before.
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
        if (board[i][j] == 1)
            return false;
    // check if the 135° diagonal had a queen before.
    for (int i = row - 1, j = col + 1; i >= 0 && j < N; --i, ++j)
        if (board[i][j] == 1)
            return false;
    return true;
}

bool placequeen(int board[N][N], int currentrow)
{
    if (currentrow == N)
        return true;

    for (int col = 0; col < N; col++) // go through the row
    {
        if (is_safe(board, currentrow, col))
        {
            board[currentrow][col] = 1; // if safe, put at current
            if (placequeen(board, currentrow + 1))
                return true;            // go to next row
            board[currentrow][col] = 0; // if unsafe anywhere, time to backtrack...
        }
    }
    return false;
}

void printBoard(int board[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << board[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    placequeen(board, 0);
    printBoard(board);
}