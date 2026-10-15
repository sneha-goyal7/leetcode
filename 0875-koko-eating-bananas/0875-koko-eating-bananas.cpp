class Solution {
public:
bool isPossible(vector<int> &arr, int n, int h, int speed) {
        long long hours = 0;
        for (int i = 0; i < n; i++) {
            hours += (arr[i] + speed - 1) / speed;
            if (hours > h) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& nums, int h) {
          int n = nums.size();

        int st = 1, end = 0, ans = -1;
        for (int i = 0; i < n; i++) end = max(end, nums[i]);

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isPossible(nums, n, h, mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                st = mid + 1;
            }
        }
        return ans;
    }
};