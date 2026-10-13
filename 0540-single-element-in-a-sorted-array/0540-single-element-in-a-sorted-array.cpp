class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
    int n = nums.size();
    int st = 0, end = n - 2;     
    while(st <= end){
        int mid = st + (end - st) / 2;
        if(nums[mid] == nums[mid ^ 1]) st = mid + 1;
        else end = mid - 1;
    }
    return nums[st];
    }
};