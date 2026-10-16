class Solution {
public:
void helper(string& s, int target, int idx, string cur, long long val, long long last, vector<string>& ans) {
        int n = s.size();
        if (idx == n) {
            if (val == target) ans.push_back(cur);
            return;
        }

        long long num = 0;
        for (int i = idx; i < n; i++) {
            if (i > idx && s[idx] == '0') break;        
            num = num * 10 + (s[i] - '0');
            string numStr = s.substr(idx, i - idx + 1);

            if (idx == 0) {
                helper(s, target, i + 1, numStr, num, num, ans);     
            } else {
                helper(s, target, i + 1, cur + "+" + numStr, val + num, num, ans);
                helper(s, target, i + 1, cur + "-" + numStr, val - num, -num, ans);
                helper(s, target, i + 1, cur + "*" + numStr, val - last + last * num, last * num, ans);
            }
        }
    }
    vector<string> addOperators(string s, int target) {
        vector<string> ans;
        helper(s, target, 0, "", 0, 0, ans);
        return ans;
    }
};