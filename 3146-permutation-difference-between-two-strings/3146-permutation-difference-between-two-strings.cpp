class Solution {
public:
    int findPermutationDifference(string s, string t) {
       int pos[26];
        int ans = 0;
        for (int i = 0; i < t.size(); i++) {
            int idx = s.find(t[i]);
            ans += abs(idx- i);
        }
        return ans; 
    }
};