// This was an interesting question that I had done some time ago
// if found 0, make the row n column 0. 
// Main part was being able to differentiate between original zeroes n the ones that were put by me. With extra space its simple.
// TC: O(m*n), SC: O(m*n)
// O(1): They used the first row and column to keep track of all the 0's... then made that row n col 0

class Solution {
public:
    
    void setrowzero(vector<vector<int>>& matrix, int row, int size)
    {
        for(int i = 0; i < size; i++)
        {
            matrix[row][i] = 0;
        }
    }
    
    void setcolzero(vector<vector<int>>& matrix, int col, int size)
    {
        for(int i = 0; i < size; i++)
        {
            matrix[i][col] = 0;
        }
    }
    
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> rows, cols;
        
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0) 
                {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }
        
        for (set<int>::iterator i = rows.begin(); i != rows.end(); i++) 
        {
            int element = *i;
            setrowzero(matrix, element, matrix[0].size());
        }
        
        for (set<int>::iterator i = cols.begin(); i != cols.end(); i++) 
        {
            int element = *i;
            setcolzero(matrix, element, matrix.size());
        }
        
    }
};