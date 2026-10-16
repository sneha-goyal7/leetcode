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

        int j = i + 1;
        while (j < nums.size() && nums[j] == nums[i]) j++;  
        solve(nums, j, cur, res);        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> cur;
        solve(nums, 0, cur, res);
        return res;
    }
};