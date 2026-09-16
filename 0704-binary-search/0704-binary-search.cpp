class Solution {
public:
    int search(vector<int>& arr, int target) {
    //    int lo = 0, hi = nums.size() - 1;

    //     while (lo <= hi) {
    //         int mid = lo + (hi - lo) / 2;

    //         if (nums[mid] == target) return mid;
    //         else if (nums[mid] < target) lo = mid + 1;
    //         else hi = mid - 1;
    //     }

    //     return -1; 
    int st=0, end=arr.size()-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(arr[mid]==target)return mid;
        else if(arr[mid]<target)st=mid+1;
        else end=mid-1;
    }
    return -1;
    }
};