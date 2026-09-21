class Solution {
public:
int reverse(long n) {
        long rn = 0;
        while(n != 0){
            int dig = n % 10;
            n = n / 10;
            rn = rn * 10 + dig;
        }
        return rn;
    }
    bool isPalindrome(int x) {
        if(x < 0) return false;      
        int rev = reverse(x);       
        return x == rev;
    }
};