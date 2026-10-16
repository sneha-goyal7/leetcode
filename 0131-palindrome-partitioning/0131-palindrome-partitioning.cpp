class Solution {
public:
bool isPal(string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void solve(string& s, int start, vector<string>& cur, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(cur);
            return;
        }
        for (int end = start; end < s.size(); end++) {
            if (isPal(s, start, end)) {
                cur.push_back(s.substr(start, end - start + 1));
                solve(s, end + 1, cur, res);
                cur.pop_back();                       
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> cur;
        solve(s, 0, cur, res);
        return res;
    }
};