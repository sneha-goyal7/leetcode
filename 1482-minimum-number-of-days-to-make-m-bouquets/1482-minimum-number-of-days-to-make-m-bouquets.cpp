class Solution {
public:
 bool isPossible(vector<int> &arr, int n, int k, int m, int day) {
        int bouquets = 0, count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] <= day) {
                count++;
                if (count == k) {
                    bouquets++;
                    count = 0;
                }
            }
            else {
                count = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
       int n = bloomDay.size();
        if ((long long)m * k > n) return -1;

        int st = INT_MAX, end = INT_MIN, ans = -1;
        for (int i = 0; i < n; i++) {
            st = min(st, bloomDay[i]);
            end = max(end, bloomDay[i]);
        }

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isPossible(bloomDay, n, k, m, mid)) {
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