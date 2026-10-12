class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<long long,int> m;    
        long long prefix = 0;
        int count = 0;     
        m[0] = 1; 
        for(int i = 0; i < nums.size(); i++){
            prefix += nums[i];
            if(m.count(prefix - k)) count += m[prefix - k]; 
            m[prefix]++;                
        }
        return count;
    }
};