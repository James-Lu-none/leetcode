class Solution {
public:
    // void merge(vector<int> &nums, int low, int mid, int high) {
    //     if (low >= high) return;
    //     int l = low, r = mid + 1, k = 0, size = high - low + 1;
    //     vector<int> sorted(size, 0);
    //     while (l <= mid and r <= high) {
    //         if (nums[l] < nums[r]) sorted[k] = nums[l++];
    //         else sorted[k] = nums[r++];
    //         k++;
    //     }
    //     while (l <= mid) sorted[k++] = nums[l++];
    //     while (r <= high) sorted[k++] = nums[r++];
    //     for (k = 0; k < size; k++) nums[k + low] = sorted[k];
    // }
    // void mergeSort(vector<int>& nums, int low, int high) {
    //     if (low >= high) return;
    //     int mid = low + (high-low)/2;
    //     mergeSort(nums, low, mid);
    //     mergeSort(nums, mid+1, high);

    //     return merge(nums, low, mid, high);
    // }
    // vector<int> sortArray(vector<int>& nums) {
    //     int n = nums.size();
    //     mergeSort(nums, 0, n-1);
    //     return nums;
    // }

    vector<int> sortArray(vector<int>& nums) {
        // counting sort
        // assumes -50000 <= nums[i] <= 50000
        const int OFFSET = 50000;
        const int SIZE = 50000 * 2 + 1;
        int arr[SIZE] = {0};
        
        // record 
        for (int i = 0; i < nums.size(); ++i) {
            arr[nums[i] + OFFSET] += 1;
        }

        // from iterate from -50000 to 50000
        for (int index = 0, i = 0; i < SIZE; ++i) {
            for (int j = 0; j < arr[i]; ++j) {
                nums[index] = i - OFFSET;
                ++index;
            }
        }

        return nums;
    }
};