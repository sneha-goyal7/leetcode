class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<int> freq(51, 0);
        for (int x : nums) freq[x]++;

        int ans = 0;
        for (int v = 1; v <= 50; v++) {
            if (freq[v] == 2) ans ^= v;
        }

        return ans;
    }
};