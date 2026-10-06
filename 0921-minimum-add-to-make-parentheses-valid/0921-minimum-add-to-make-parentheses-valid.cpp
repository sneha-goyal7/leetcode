class Solution {
public:
    int minAddToMakeValid(string s) {
        int openNeeded = 0;  // unmatched '(' that need a ')'
        int closeNeeded = 0; // unmatched ')' that need a '('

        for (char c : s) {
            if (c == '(') {
                openNeeded++;
            } else {
                if (openNeeded > 0) openNeeded--;
                else closeNeeded++;
            }
        }

        return openNeeded + closeNeeded;
    }
};