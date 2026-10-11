class Solution {
public:
void merge(vector<int>& arr, int s, int mid, int e) {
    vector<int> temp;
    int i = s, j = mid + 1;
    while (i <= mid && j <= e) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= e) temp.push_back(arr[j++]);

    for (int k = 0; k < temp.size(); k++)
        arr[s + k] = temp[k];
}

long long countPairs(vector<int>& arr, int s, int mid, int e) {
    long long cnt = 0;
    int j = mid + 1;
    for (int i = s; i <= mid; i++) {
        while (j <= e && (long long)arr[i] > 2LL * arr[j]) j++;
        cnt += (j - (mid + 1));
    }
    return cnt;
}

long long mergeSort(vector<int>& arr, vector<int>& temp, int s, int e) {
    if (s >= e) return 0;
    int mid = s + (e - s) / 2;
    long long cnt = mergeSort(arr, temp, s, mid);
    cnt += mergeSort(arr, temp, mid + 1, e);
    cnt += countPairs(arr, s, mid, e);
    merge(arr, s, mid, e);
    return cnt;
}
    int reversePairs(vector<int>& nums) {
        vector<int> temp(nums.size());
    return (int)mergeSort(nums, temp, 0, (int)nums.size() - 1);  
    }
};