class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;

        function<void(int)> backtrack = [&](int start) {
            if (curr.size() == k) {
                ans.push_back(curr);
                return;
            }

            for (int i = start; i <= n - (k - curr.size()) + 1; i++) {
                curr.push_back(i);
                backtrack(i + 1);
                curr.pop_back();
            }
        };

        backtrack(1);
        return ans;
    }
};