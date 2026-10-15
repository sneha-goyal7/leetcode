class Solution {
public:
   bool isPossible(vector<int>& weights, int days, int cap) {
        int dayCount = 1, load = 0;
        for (int w : weights) {
            if (load + w > cap) {
                dayCount++;
                load = w;
            }
            else {
                load += w;
            }
        }
        return dayCount <= days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
         int st = 0, end = 0, ans = -1;
        for (int w : weights) {
            st = max(st, w);
            end += w;
        }

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isPossible(weights, days, mid)) {
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