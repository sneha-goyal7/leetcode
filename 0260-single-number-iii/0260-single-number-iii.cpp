class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
    long long xr = 0;
    for (int x : nums) xr ^= x;   
    long long diff = xr & -xr; 
    int a=0,b=0;    
    for (int x : nums) {
        if (x & diff) a ^= x;            // group 1
        else b ^= x;                     // group 2
    }
     if (a > b) swap(a, b);
    return {a, b};
    }
};