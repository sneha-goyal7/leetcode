class Solution {
public:
void solve(vector<int>& nums, int i, int target, vector<int>& cur, vector<vector<int>>& res) {
        if (i == nums.size()) {
            if (target == 0) res.push_back(cur);
            return;
        }
        if (nums[i] <= target) {
            cur.push_back(nums[i]);                       
            solve(nums, i + 1, target - nums[i], cur, res);  
            cur.pop_back();                    
        }

        int j = i + 1;                           
        while (j < nums.size() && nums[j] == nums[i]) j++;
        solve(nums, j, target, cur, res);                  
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());    
        vector<vector<int>> res;
        vector<int> cur;
        solve(candidates, 0, target, cur, res);
        return res;
    }
};