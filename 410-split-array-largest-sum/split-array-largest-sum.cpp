class Solution {
public:
    bool canFit(vector<int>& nums, int k, int x) {
        int count = 1;
        int sum = 0;
        for (int num: nums){
            if(sum + num > x) {
                count++;
                sum = num;
            } else {
                sum += num;
            }
        }
        return count <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        // Given a maximum allowed sum X, can I split the array into k bags (or fewer)?
        // If you can't do it with a limit of X = 17, you definitely can't do it with X = 16, X = 15, etc.
        // If you can do it with a limit of X = 18, you definitely can do it with X = 19, X = 20, etc. (a bigger bag only makes it easier).
        // This creates a "sorted" range of answers: [No, No, No, No, Yes, Yes, Yes, Yes]
        // and we are looking for the very first "Yes". This is a perfect job for Binary Search.
        int n = nums.size();
        int low = 0;
        int high = 0;
        for (int num:nums) {
            high+=num;
            low = max(low, num);
        }
        int ans;
        while (low <= high) {
            int mid = low + (high-low)/2;
            if (canFit(nums, k, mid)) {
                high = mid-1;
                ans = mid;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};