class Solution {
public:
    bool check(vector<int>& nums,int i=0,int count=0) {
        int n = nums.size();
        if (count > 1) return false;         
        if (i == n) return true;                  
        if (nums[i] > nums[(i + 1) % n]) count++;    
        return check(nums, i + 1, count);
    }
};