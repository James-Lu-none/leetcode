class Solution {
public:
    int reversePairs(vector<int>& nums) {
        if (nums.empty()) return 0;
        return mergeSort(nums, 0, nums.size() - 1);
    }
    int mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return 0;
        int mid = low + (high - low) / 2;
        int count = mergeSort(nums, low, mid) + mergeSort(nums, mid + 1, high);
        int j = mid + 1;
        for (int i = low; i <= mid; i++) {
            while (j <= high && (long long)nums[i] > 2LL * nums[j]) {
                j++;
            }
            count += (j - (mid + 1));
        }
        inplace_merge(nums.begin() + low, nums.begin() + mid + 1, nums.begin() + high + 1);
        return count;
    }

    // int count = 0;
    // void countPairs(vector<int>& left, vector<int>& right) {
    //     int j = 0;
    //     // since left and right is sorted, so if left[i] > right[j]*2
    //     // then left[i] to left.end() will also larger then right.begin() to right[j] times 2
    //     // so j doesn't have to restart from 0, making countPairs = O(n)
    //     // ex: [2, 5, 6] [1, 2, 5]
    //     // i = 0: j = 0; count += 0;
    //     // i = 1: j = 0+(1+1); count+=2;
    //     // i = 2: j = 0+(1+1)+0; count+=2;
    //     // count: 4
    //     for (int i = 0; i < left.size(); i++) {
    //         while (j < right.size() && (long long)left[i] > right[j]*2LL) {
    //             j++;
    //         }
    //         count += j;
    //     }
    // }
    // vector<int> merge(vector<int>& left, vector<int>& right) {
    //     int i = 0;
    //     int j = 0;
    //     vector<int> a = {};
    //     int n = left.size();
    //     int m = right.size();
    //     while (i<n && j<m) {
    //         if (left[i] < right[j]) a.push_back(left[i++]);
    //         else a.push_back(right[j++]);
    //     }
    //     while (i<n) a.push_back(left[i++]);
    //     while (j<m) a.push_back(right[j++]);
    //     return a;
    // }
    // vector<int> mergeSort(vector<int>& nums) {
    //     int n = nums.size();
    //     if (n <= 1) return nums;
    //     int mid = n/2;
    //     vector<int> left(nums.begin(), nums.begin()+mid);
    //     vector<int> right(nums.begin()+mid, nums.end());

    //     vector<int> leftSorted = mergeSort(left);
    //     vector<int> rightSorted = mergeSort(right);
        
    //     countPairs(leftSorted, rightSorted);
        
    //     return merge(leftSorted, rightSorted);        
    // }
    // int reversePairs(vector<int>& nums) {
    //     auto v = mergeSort(nums);
    //     return count;
    // }
};