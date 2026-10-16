class Solution {
public:
void solve(vector<int>& nums, int i, int target, vector<int>& cur, vector<vector<int>>& res) {
        if (i == nums.size()) {
            if (target == 0) res.push_back(cur);
            return;
        }
        if (nums[i] <= target) {
            cur.push_back(nums[i]);                       
            solve(nums, i, target - nums[i], cur, res);   
            cur.pop_back();                                
        }
        solve(nums, i + 1, target, cur, res);              
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        solve(candidates, 0, target, cur, res);
        return res;
    }
};