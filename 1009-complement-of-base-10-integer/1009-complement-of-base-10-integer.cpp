class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0) return 1;
        unsigned int mask = 1;
        while (mask <= (unsigned)n) mask <<= 1;   // smallest power of 2 above n
        return (mask - 1) ^ n;
    }
};