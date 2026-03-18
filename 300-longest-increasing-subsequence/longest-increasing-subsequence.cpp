class Solution {
public:
    int search(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size()-1;
        while (left<=right) {
            int mid = left + (right - left)/2;
            int midVal = nums[mid];
            if (midVal >= target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return left;
    }
    int lengthOfLIS(vector<int>& nums) {
        // LIS[n] = 1+max{LIS[k]|k<n, A[k]<A[n]}
        // 如果 n 比 seq 所有數值都還大，那就 push_back n 
        // 否則找 seq 中第一個比 n 還要大的數值的位置然後取代他
        vector<int> seq = {};
        seq.push_back(nums[0]);
        for (int i = 1; i<nums.size(); i++) {
            int n = nums[i];
            printf("i= %d ", i);
            if (n > seq.back()) {
                seq.push_back(n);
                printf("push largest value %d\n", n);
            } else {
                int index = search(seq, n);
                seq[index] = n;
                printf("update %d at index: %d\n", n, index);
            }
        }

        for (int n: seq) {
            printf("%d ", n);
        }
        return seq.size();
    }
};