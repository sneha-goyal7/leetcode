class Solution {
public:
    long long maxProduct(string s) {
       int n = s.size();

        // Manacher: d1[i] = number of odd palindromes centered at i
        vector<int> d1(n);
        for (int i = 0, l = 0, r = -1; i < n; i++) {
            int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
            while (i - k >= 0 && i + k < n && s[i - k] == s[i + k]) k++;
            d1[i] = k;
            if (i + k - 1 > r) {
                l = i - k + 1;
                r = i + k - 1;
            }
        }

        // pre[i] = longest odd palindrome in s[0..i]
        // suf[i] = longest odd palindrome in s[i..n-1]
        vector<int> pre(n, 1), suf(n, 1);

        for (int i = 0; i < n; i++) {
            int len = 2 * d1[i] - 1;
            pre[i + d1[i] - 1] = max(pre[i + d1[i] - 1], len);
            suf[i - d1[i] + 1] = max(suf[i - d1[i] + 1], len);
        }

        // Prefix: shorter palindromes of same center end earlier (len - 2)
        for (int i = n - 2; i >= 0; i--) pre[i] = max(pre[i], pre[i + 1] - 2);
        for (int i = 1; i < n; i++) pre[i] = max(pre[i], pre[i - 1]);

        // Suffix: same idea, mirrored
        for (int i = 1; i < n; i++) suf[i] = max(suf[i], suf[i - 1] - 2);
        for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i], suf[i + 1]);

        long long ans = 1;
        for (int i = 0; i + 1 < n; i++)
            ans = max(ans, (long long)pre[i] * suf[i + 1]);

        return ans; 
    }
};