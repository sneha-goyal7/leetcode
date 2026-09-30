class Solution {
    void possibleSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& allSubsets) {
        if(i==nums.size()){
            allSubsets.push_back(ans);
            return;
        }
        ans.push_back(nums[i]);
        possibleSubsets(nums,ans,i+1,allSubsets);
        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1])idx++;
        possibleSubsets(nums,ans,idx,allSubsets);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> allSubsets;
        vector<int> ans;
        possibleSubsets(nums, ans, 0, allSubsets);
        return allSubsets;
    }
};