class Solution {
public:
 void solve(vector<int>& nums, int i, vector<int>& cur, vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(cur);
            return;
        }
        cur.push_back(nums[i]);  
        solve(nums, i + 1, cur, res);
        cur.pop_back();                
        solve(nums, i + 1, cur, res);     
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cur;
        solve(nums, 0, cur, res);
        return res;
    }
};