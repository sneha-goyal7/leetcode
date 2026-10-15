class Solution {
public:
 void solve(string &cur, int depth, int opened, int n, vector<string> &res) {
        if ((int)cur.size() == 2 * n) {  
            res.push_back(cur);
            return;
        }
        if (opened < n) {                
            cur.push_back('(');
            solve(cur, depth + 1, opened + 1, n, res);
            cur.pop_back();                
        }
        if (depth > 0) {                    
            cur.push_back(')');
            solve(cur, depth - 1, opened, n, res);
            cur.pop_back();                 
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur = "";
        solve(cur, 0, 0, n, res);
        return res;
    }
};