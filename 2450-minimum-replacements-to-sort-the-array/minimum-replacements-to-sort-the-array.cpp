class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int last = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] > last) {
                // every we split, we want to get the largest value, and the largest value is by dividing it even pieces
                // ex: nums = [..., 11, 5]
                // => nums = [..., {3, 4, 4}, 5]
                // we need to split 11 by ceil(nums[i]/last) times which is (nums[i] + last - 1) / last
                // it requires k-1 operations
                long long k = (nums[i] + last - 1) / last;
                ans += (k - 1);
                
                // update the last value with largest value possible 11/3 = 3
                last = nums[i] / k;
            } else {
                last = nums[i];
            }
        }
        return ans;
    }
};