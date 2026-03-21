class Solution {
public:
    void merge(vector<int> &nums, int low, int mid, int high) {
        if (low >= high) return;
        int l = low, r = mid + 1, k = 0, size = high - low + 1;
        vector<int> sorted(size, 0);
        while (l <= mid and r <= high) {
            if (nums[l] < nums[r]) sorted[k] = nums[l++];
            else sorted[k] = nums[r++];
            k++;
        }
        while (l <= mid) sorted[k++] = nums[l++];
        while (r <= high) sorted[k++] = nums[r++];
        for (k = 0; k < size; k++) nums[k + low] = sorted[k];
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low >= high) return;
        int mid = low + (high-low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);

        return merge(nums, low, mid, high);
    }
    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return nums;
    }
};