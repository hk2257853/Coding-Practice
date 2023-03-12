class Solution
{
public:
    bool isSafe(vector<vector<char>> &board, int x, int y, char val)
    {
        for (int i = 0; i < 9; i++)
            if (board[x][i] == val)
                return false; // checking row
        for (int i = 0; i < 9; i++)
            if (board[i][y] == val)
                return false; // checking col

        int row = x - x % 3, col = y - y % 3; // get start of the 3x3 grid
        for (int i = 0; i < 3; i++)           // for 3x3 grid
        {
            for (int j = 0; j < 3; j++)
            {
                if (board[row + i][col + j] == val)
                    return false;
            }
        }

        return true;
    }

    bool solving(vector<vector<char>> &board, int x, int y)
    {
        // base (last case...)
        if (x == 9)
            return true;
        if (y == 9)
            return solving(board, x + 1, 0);

        if (board[x][y] != '.')
            return solving(board, x, y + 1); // prefilled number, skip

        for (char i = '1'; i <= '9'; i++)
        {
            if (isSafe(board, x, y, i)) // if safe
            {
                board[x][y] = i; // put
                if (solving(board, x, y + 1))
                    return true; // try next
                board[x][y] = '.';
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>> &board)
    {
        solving(board, 0, 0);
    }
};