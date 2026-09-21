class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;      
        vector<char> isComposite(n, 0);
        int ans = 1;        
        for(int i = 3; i < n; i += 2){  
            if(!isComposite[i]){
                ans++;
                for(long j = (long)i * i; j < n; j += 2*i){ 
                    isComposite[j] = 1;
                }
            }
        }      
        return ans;
    }
};