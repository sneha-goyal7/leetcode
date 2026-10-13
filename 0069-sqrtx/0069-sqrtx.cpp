class Solution {
public:
    int mySqrt(int n) {
        long long st = 1, end = n;
        int ans = 0;
        while(st <= end){
            long long mid = st + (end - st) / 2;
            if(mid * mid <= n){
                ans = mid;
                st = mid + 1;
            }
            else end = mid - 1;
        }
        return ans;
    }
};