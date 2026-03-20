class Solution {
public:
    // int mergeSort(vector<int>& nums, int low, int high) {
    //     if (low >= high) return 0;
    //     int mid = low + (high - low) / 2;
    //     int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);
    //     int j = mid + 1;
    //     for (int i = low; i <= mid; i++) {
    //         while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
    //             j++;
    //         }
    //         count += (j - (mid + 1));
    //     }
    //     inplace_merge(nums.begin() + low, nums.begin() + mid + 1, nums.begin() + high + 1);
    //     return count;
    // }
    // int reversePairs(vector<int>& nums) {
    //     if (nums.empty()) return 0;
    //     return mergeSort(nums, 0, nums.size() - 1);
    // }

    int count = 0;
    void countPairs(vector<int>& nums, int low, int mid, int high) {
        
        // since left and right is sorted, so if left[i] > right[j]*2
        // then left[i] to left.end() will also larger then right.begin() to right[j] times 2
        // so j doesn't have to restart from 0, making countPairs = O(n)
        // ex: [2, 5, 6] [1, 2, 5]
        // i = 0: j = 0; count += 0;
        // i = 1: j = 0+(1+1); count+=2;
        // i = 2: j = 0+(1+1)+0; count+=2;
        // count: 4
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
    }
    void merge(vector<int>& nums, int low, int mid, int high) {
        vector<int> temp;
        int i = low, j = mid + 1;
        
        while (i <= mid && j <= high) {
            if (nums[i] <= nums[j]) temp.push_back(nums[i++]);
            else temp.push_back(nums[j++]);
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= high) temp.push_back(nums[j++]);
        for (int p = 0; p < temp.size(); p++) {
            nums[low + p] = temp[p];
        }
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int mid = low + (high-low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        countPairs(nums, low, mid, high);
        
        return merge(nums, low, mid, high);
    }
    int reversePairs(vector<int>& nums) {
        mergeSort(nums, 0, nums.size()-1);
        return count;
    }
};