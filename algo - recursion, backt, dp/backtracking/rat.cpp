#include "iostream"
using namespace std;
#define N 4

// this code is easier compared to others.

int soln[N][N];

// is current decision safe
bool isSafe(int arr[N][N], int x, int y)
{
    if (x < N && y < N && arr[x][y] == 1)
        return true;

    return false;
}

// TODO: code in English like I do for recursion (prob & subprob)
bool ratinMaze(int arr[N][N], int x, int y, int soln[N][N])
{
    if (x == N - 1 && y == N - 1) // base case
    {
        soln[x][y] = 1;
        return true;
    }

    /*
        1st add to soln
        If can move right or left(decision/relation betw prob & subprob - any works) from here... move any 1 (thus next subproblem)
        If can't, wrong ans taken in, backtrack.
    */
    if (isSafe(arr, x, y))
    {
        soln[x][y] = 1;
        // there r 2 possibilities... its enough if anyone is correct.
        if (ratinMaze(arr, x + 1, y, soln))
            return true; // moving right
        if (ratinMaze(arr, x, y + 1, soln))
            return true; // moving down

        // Can't go down or right
        soln[x][y] = 0; // backtrack.
        return false;
    }

    return false; // if not safe
}

void printSolution(int sol[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf(" %d ", sol[i][j]);
        printf("\n");
    }
}

int main()
{
    int m[N][N] =
        {{1, 1, 1, 1},
         {1, 1, 0, 1},
         {0, 1, 0, 1},
         {0, 1, 1, 1}};
    ratinMaze(m, 0, 0, soln);
    printSolution(soln);
}

// the core part remains safe for all backtraking prob... so byheart 1-2 as a template & practice some...

// variations: if all 4 directions were allowed, or return all correct routes.
// not doing for now... very low chance that they will ask those ques... Keep these if leveling to next level.