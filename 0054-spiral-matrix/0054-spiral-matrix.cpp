class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
         vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int top = 0, bottom = m - 1, left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            // left -> right (top row)
            for (int j = left; j <= right; j++)
                res.push_back(matrix[top][j]);
            top++;

            // top -> bottom (right col)
            for (int i = top; i <= bottom; i++)
                res.push_back(matrix[i][right]);
            right--;

            // right -> left (bottom row) -- only if top<=bottom still valid
            if (top <= bottom) {
                for (int j = right; j >= left; j--)
                    res.push_back(matrix[bottom][j]);
                bottom--;
            }

            // bottom -> top (left col) -- only if left<=right still valid
            if (left <= right) {
                for (int i = bottom; i >= top; i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
        }
        return res;
    }
};