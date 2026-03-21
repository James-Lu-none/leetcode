class Solution {
public:
    // convert "find nums of subarrays where target is the majority element" problem to "find nums of inversion pairs"
    // and use merge sort to divide and conquer it
    uint64_t count = 0;
    void merge (vector<int>& nums, int low, int mid, int high) {
        int i = low;
        int j = mid+1;
        int k = 0;
        vector<int> sorted(high-low+1);

        // before merge, calculate nums of inversion pairs O(n)
        // same as 493. Reverse Pairs (Hard)
        int m = mid+1;
        for (int n = low; n<=mid; n++) {
            // move to next m if right pointer less then right (meas its not inverse)
            while (m <= high && nums[m]<=nums[n]) {
                m++;
            }
            // now inversion fount at current m, so from nums[m..high] are all forming inverse pair with i
            count+=high-m+1;
        }

        while (i <= mid && j <= high) {
            if (nums[i] < nums[j]) sorted[k++] = nums[i++];
            else sorted[k++] = nums[j++];
        }
        while (i <= mid) sorted[k++] = nums[i++];
        while (j <= high) sorted[k++] = nums[j++];
        while (k--) nums[low+k] = sorted[k];
        
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low>=high) return;
        int mid = low + (high-low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        return merge(nums, low, mid, high);
    }
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // prefixSum has length +1 for first element 0
        vector<int> prefixSum(n+1, 0);
        for(int i=0; i<n; i++) {
            int val = (nums[i] == target)?1:-1;
            prefixSum[i+1] = prefixSum[i] + val;
        }
        // find inversion pairs
        mergeSort(prefixSum, 0, n);
        return count;
    }
};