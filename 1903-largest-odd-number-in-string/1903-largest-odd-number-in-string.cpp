class Solution {
public:
    string largestOddNumber(string num) {
       int n=num.size();
       int st=0,end=n-1;
       for(int i=0;i<n;i++){
        if((num[i]-'0')%2==1)end=i;
       } 
       if((num[end]-'0')%2==0)return "";
       while(st<end && num[st]=='0')st++;
       string ans="";
       for(int i=st;i<=end;i++)ans+=num[i];
       return ans;
    }
};