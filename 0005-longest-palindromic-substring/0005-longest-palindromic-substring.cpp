class Solution {
public:
    string longestPalindrome(string s) {
         string t = "^";
        for (char c : s) {
            t += '#';
            t += c;
        }
        t += "#$";

        int n = t.size();
        vector<int> p(n, 0);
        int center = 0, right = 0;

        for (int i = 1; i < n - 1; i++) {
            if (i < right)
                p[i] = min(right - i, p[2 * center - i]);

            while (t[i + 1 + p[i]] == t[i - 1 - p[i]])
                p[i]++;

            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }

        int maxLen = 0, centerIdx = 0;
        for (int i = 1; i < n - 1; i++) {
            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIdx = i;
            }
        }

        return s.substr((centerIdx - maxLen) / 2, maxLen);
    }
};