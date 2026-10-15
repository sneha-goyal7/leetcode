class Solution {
public:
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        int m = arr1.size(), n = arr2.size();
        arr1.resize(m + n);  
        int idx = m + n - 1, i = m - 1, j = n - 1;
        while (i >= 0 && j >= 0) {
            if (arr1[i] >= arr2[j]) arr1[idx--] = arr1[i--];
            else                    arr1[idx--] = arr2[j--];
        }
        while (j >= 0) {
            arr1[idx--] = arr2[j--];
        }

        int total = m + n;
        if (total % 2 == 1) return arr1[total / 2];                    
        return ((double)arr1[total / 2 - 1] + arr1[total / 2]) / 2.0; 
    }
};