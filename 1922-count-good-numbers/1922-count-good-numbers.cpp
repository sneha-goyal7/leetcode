class Solution {
public:
const long long MOD = 1e9 + 7;

    long long power(long long base, long long exp) {
        long long res = 1;
        base %= MOD;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % MOD;  
            base = (base * base) % MOD;
            exp >>= 1;
        }
        return res;
    }
    int countGoodNumbers(long long n) {
        long long evenCnt = (n + 1) / 2;  
        long long oddCnt = n / 2;         
        long long ans = (power(5, evenCnt) * power(4, oddCnt)) % MOD;
        return (int)ans;
    }
};