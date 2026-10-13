class Solution {
public:
    int hammingWeight(int n) {
    unsigned int x = n;
    int count = 0;
    while (x) {
        x &= (x - 1);  
        count++;
    }
    return count;
    }
};