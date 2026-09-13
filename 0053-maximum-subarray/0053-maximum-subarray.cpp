class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // int maxsum=INT_MIN;
        // for(int st=0;st<n.size();st++){
        //    int currsum=0;
        // for(int end=st;end<n.size();end++){
        //     currsum+=n[end];
        //     maxsum=max(currsum,maxsum);
        // }
        // }
        // return maxsum;


       int currSum=0,maxSum=INT_MIN;
       for(int val:nums){
        currSum+=val;
        maxSum=max(currSum,maxSum);
        if(currSum<0){
            currSum=0;
        }
       } 
       return maxSum;
    }
};