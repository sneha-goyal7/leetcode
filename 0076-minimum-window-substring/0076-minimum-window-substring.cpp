class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<char, int> need;
        for (char c : t) {
            need[c]++;
        }

        int left = 0;
        int count = t.size();   // total characters still needed
        int start = 0;          // start of the best window
        int minLen = INT_MAX;   // length of the best window

        for (int right = 0; right < s.size(); right++) {
            // add s[right] to the window
            if (need[s[right]] > 0) {
                count--;
            }
            need[s[right]]--;

            // window has everything, so try to make it smaller
            while (count == 0) {
                if (right - left + 1 < minLen) {
                    minLen = right - left + 1;
                    start = left;
                }
                // remove s[left] from the window
                need[s[left]]++;
                if (need[s[left]] > 0) {
                    count++;
                }
                left++;
            }
        }

        if (minLen == INT_MAX) {
            return "";
        }
        return s.substr(start, minLen);
    }
};