class Solution {
public:
    bool search(vector<int>& nums, int k) {
        int st = 0, end = nums.size() - 1;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(nums[mid] == k) return true;
            if(nums[st] == nums[mid] && nums[mid] == nums[end]){
                st++;
                end--;
            }
            else if(nums[st] <= nums[mid]){         
                if(nums[st] <= k && k < nums[mid]) end = mid - 1;
                else st = mid + 1;
            }
            else{                  
                if(nums[mid] < k && k <= nums[end]) st = mid + 1;
                else end = mid - 1;
            }
        }
        return false;
    }
};