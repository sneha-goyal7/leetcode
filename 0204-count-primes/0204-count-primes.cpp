class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;
        vector<bool>isPrime(n, 0);
        for (int i = 3; i * i < n; i += 2) {
            if (!isPrime[i]) {
                for (int j = i * i; j < n; j += 2 * i)
                    isPrime[j] = 1;
            }
        }
        int ans = 1;
        for (int i = 3; i < n; i += 2) {
            if (!isPrime[i]) ans++;
        }

        return ans;
    }
};