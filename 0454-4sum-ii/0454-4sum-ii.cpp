class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int n = nums1.size();
        unordered_map<int,int> mp;
        mp.reserve(n * n * 2);     
        for (int a : nums1)
            for (int b : nums2)
                mp[a + b]++;       
        int count = 0;
        for (int c : nums3)
            for (int d : nums4) {
                auto it = mp.find(-(c + d));  
                if (it != mp.end()) count += it->second;
            }
        return count;
    }
};