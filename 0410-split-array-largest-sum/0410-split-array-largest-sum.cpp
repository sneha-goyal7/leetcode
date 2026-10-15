class Solution {
public:
 bool isPossible(vector<int>& a, int k, int maxSum) {
        int parts = 1;
        long long load = 0;
        for (int x : a) {
            if (load + x > maxSum) {
                parts++;
                load = x;
            }
            else {
                load += x;
            }
        }
        return parts <= k;
    }

    int splitArray(vector<int>& a, int k) {
        int st = 0, ans = -1;
        long long end = 0;
        for (int x : a) {
            st = max(st, x);
            end += x;
        }

        while (st <= end) {
            int mid = st + (end - st) / 2;
            if (isPossible(a, k, mid)) {
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