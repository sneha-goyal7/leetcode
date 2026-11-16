class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        stringstream ss(path);
        string token;

        while (getline(ss, token, '/')) {
            if (token.empty() || token == ".") continue;
            if (token == "..") {
                if (!st.empty()) st.pop_back();
            } else {
                st.push_back(token);
            }
        }

        string res;
        for (auto &dir : st) {
            res += "/" + dir;
        }
        return res.empty() ? "/" : res;
    }
};