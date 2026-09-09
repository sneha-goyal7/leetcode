class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        long long threshold = 1000; // 10^3

        for (int k = 0; k < 5; k++) { // n up to 10^15, so thresholds 10^3..10^15
            if (n >= threshold) {
                ans += (n - threshold + 1);
            } else {
                break;
            }
            threshold *= 1000;
        }

        return ans;
    }
};