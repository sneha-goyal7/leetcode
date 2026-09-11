class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxProd = nums[0];
        int currentMax = nums[0];
        int currentMin = nums[0];

        for (int i = 1; i < (int)nums.size(); i++) {
            int num = nums[i];

            if (num < 0)
            swap(currentMax, currentMin);

            currentMax = max(num, currentMax * num);
            currentMin = min(num, currentMin * num);
            maxProd = max(maxProd, currentMax);
        }

        return maxProd;

    }
};