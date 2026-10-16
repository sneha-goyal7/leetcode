class Solution {
public:
 void solve(string& digits, int i, string& cur, vector<string>& res, vector<string>& mp) {
        if (i == digits.size()) {
            res.push_back(cur);
            return;
        }
        string letters = mp[digits[i] - '0'];
        for (char ch : letters) {
            cur.push_back(ch);                 
            solve(digits, i + 1, cur, res, mp);
            cur.pop_back();                     
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if (digits.empty()) return res;       
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string cur;
        solve(digits, 0, cur, res, mp);
        return res;
    }
};