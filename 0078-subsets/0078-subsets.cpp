class Solution {
    void getallSubsets(vector<int>&nums,vector<int>&ans,int i,vector<vector<int>>&allSubsets){
        if(i==nums.size()){
            allSubsets.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        getallSubsets(nums,ans,i+1,allSubsets);
        ans.pop_back();
        getallSubsets(nums,ans,i+1,allSubsets);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>allSubsets;
        vector<int>ans;
        getallSubsets(nums,ans,0,allSubsets);
        return allSubsets;

        /* int n = nums.size();
    vector<vector<int>> ans;

    for (int mask = 0; mask < (1 << n); mask++) {
        vector<int> cur;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) cur.push_back(nums[i]);
        }
        ans.push_back(cur);
    }
    return ans;*/
    }
};