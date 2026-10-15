class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
         int n = mat.size();
        int m = mat[0].size();
        int st = 0, end = m - 1;
        while (st < end) {
            int mid = st + (end - st) / 2;
            int r = 0;
            for (int i = 1; i < n; i++)
                if (mat[i][mid] > mat[r][mid]) r = i;
            if (mat[r][mid] < mat[r][mid + 1]) st = mid + 1;
            else end = mid;
        }
        int r = 0;
        for (int i = 1; i < n; i++)
            if (mat[i][st] > mat[r][st]) r = i;

        return {r, st};
    }
};