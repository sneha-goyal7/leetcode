class Solution {
public:
    string toHex(int num) {
        if (num == 0) return "0";
        unsigned int n = num;
        string h = "0123456789abcdef", res;
        while (n > 0) { res += h[n % 16]; n /= 16; }
        reverse(res.begin(), res.end());
        return res;
    }
};