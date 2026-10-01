class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
      vector<int>freq(51,0);
      int  ans=0;
      for(int val:nums)freq[val]++;
      for(int i=1;i<51;i++){
        if(freq[i]==2)ans^=i;
      } 
      return ans;
    }
};