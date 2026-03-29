class Solution {
public:
    vector<int> counts;
    // instead of sorting on nums, we will sort on indices so we can always obtain the correct number from nums while
    // adding smaller elements count to correct counts
    vector<int> indices;
    void mergeAndCount (vector<int>& nums, int low, int high) {
        if (low>=high) return;
        vector<int> temp(high-low+1);
        int mid = low+(high-low)/2;
        int i = low;
        int j = mid+1;
        int k = 0;
        while (i <= mid && j <= high) {
            // sort from large to small
            if (nums[indices[i]]>nums[indices[j]]) {
                counts[indices[i]]+=high-j+1;
                temp[k++] = indices[i++];
            } else {
                temp[k++] = indices[j++];
            }
        }
        while (i <= mid) temp[k++] = indices[i++];
        while (j <= high) temp[k++] = indices[j++];

        while (k--) indices[k+low] = temp[k];
        return;
    }
    void mergeSort(vector<int>& nums, int low, int high) {
        if (low>=high) return;
        int mid = low + (high-low)/2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        return mergeAndCount(nums, low, high);
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        counts.resize(n);
        indices.resize(n);
        for (int i=0;i<n;i++){
            counts[i] = 0;
            indices[i] = i;
        }
        mergeSort(nums, 0, n-1);
        return counts;
    }
};