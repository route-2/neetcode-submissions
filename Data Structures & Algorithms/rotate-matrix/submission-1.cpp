class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
         int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }

    // Reverse each row
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n / 2; ++j)
        {
            // For a row of length n, you only need to swap the first n/2 elements with the last n/2 elements to reverse the entire row.
            //(till the midpoint)
            int tmp = matrix[i][j];
            matrix[i][j] = matrix[i][n - j - 1];
            matrix[i][n - j - 1] = tmp;
        }
    }
    }
};
