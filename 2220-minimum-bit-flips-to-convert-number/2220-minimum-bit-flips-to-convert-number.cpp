class Solution {
public:
    int minBitFlips(int start, int goal) {
    unsigned int x = start ^ goal; 
    int count = 0;
    while (x) {
        x &= (x - 1);
        count++;
    }
    return count;
    }
};