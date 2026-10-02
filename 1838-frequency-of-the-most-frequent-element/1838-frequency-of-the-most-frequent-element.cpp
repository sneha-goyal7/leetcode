class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
         sort(nums.begin(), nums.end());
        long long sum = 0;      // window ka sum
        int left = 0, ans = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];

            // cost = target * size - sum
            while ((long long)nums[right] * (right - left + 1) - sum > k) {
                sum -= nums[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};