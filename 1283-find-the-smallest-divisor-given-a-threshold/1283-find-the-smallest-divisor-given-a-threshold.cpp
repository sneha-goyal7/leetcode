class Solution {
public:
    int smallestDivisor(vector<int>& nums, int limit) {
        int st = 1, end = *max_element(nums.begin(), nums.end());
        int ans = end;
        while(st <= end){
            int mid = st + (end - st) / 2;

            long long sum = 0;
            for(int i = 0; i < nums.size(); i++){
                sum += (nums[i] + mid - 1) / mid;
            }

            if(sum <= limit){
                ans = mid;
                end = mid - 1;
            }
            else st = mid + 1;
        }
        return ans;
    }
};