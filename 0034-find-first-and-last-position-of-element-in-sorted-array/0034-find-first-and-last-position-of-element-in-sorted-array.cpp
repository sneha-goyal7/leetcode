class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
         int n = nums.size();

        // Lower bound: pehla index jahan nums[i] >= target
        int st = 0, end = n - 1;
        int lb = n;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(nums[mid] >= target){
                lb = mid;
                end = mid - 1;
            }
            else st = mid + 1;
        }

        // target present hi nahi hai
        if(lb == n || nums[lb] != target) return {-1, -1};

        // Upper bound: pehla index jahan nums[i] > target
        st = 0, end = n - 1;
        int ub = n;
        while(st <= end){
            int mid = st + (end - st) / 2;
            if(nums[mid] > target){
                ub = mid;
                end = mid - 1;
            }
            else st = mid + 1;
        }

        return {lb, ub - 1};
    }
};