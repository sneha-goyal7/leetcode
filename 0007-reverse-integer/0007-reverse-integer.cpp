class Solution {
public:
    int reverse(int n) {
        long rn=0;
        while(n!=0){
            int dig=n%10;
            n=n/10;
            rn=rn*10+dig;
            if(rn > INT_MAX || rn < INT_MIN) return 0;
        }
        return (int)rn;
    }
};