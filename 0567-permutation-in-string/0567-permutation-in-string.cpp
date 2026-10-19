class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        if (n > m) return false;

        int diff[26] = {0};
        for (int i = 0; i < n; i++) {
            diff[s1[i] - 'a']++;
            diff[s2[i] - 'a']--;
        }

        int nonZero = 0;
        for (int i = 0; i < 26; i++)
            if (diff[i] != 0) nonZero++;

        for (int i = n; i < m; i++) {
            if (nonZero == 0) return true;

            // window mein aane wala char
            if (diff[s2[i] - 'a'] == 0) nonZero++;
            diff[s2[i] - 'a']--;
            if (diff[s2[i] - 'a'] == 0) nonZero--;

            // window se jaane wala char
            if (diff[s2[i - n] - 'a'] == 0) nonZero++;
            diff[s2[i - n] - 'a']++;
            if (diff[s2[i - n] - 'a'] == 0) nonZero--;
        }
        return nonZero == 0;
    }
};