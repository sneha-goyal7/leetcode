class Solution {
public:
void solve(int num, int k, int target, vector<int>& cur, vector<vector<int>>& res) {
        if (num > 9) {
            if (target == 0 && cur.size() == k) res.push_back(cur);
            return;
        }
        if (num <= target && cur.size() < k) {
            cur.push_back(num);
            solve(num + 1, k, target - num, cur, res);
            cur.pop_back();                 
        }
        solve(num + 1, k, target, cur, res);   
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> cur;
        solve(1, k, n, cur, res);
        return res;
    }
};