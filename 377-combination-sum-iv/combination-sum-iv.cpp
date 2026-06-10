class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        // problem: numbers of possible combination to get target
        // subproblem: numbers of possible combinations to reach i
        vector<long long> dp(target+1,0);
        // base case, numbers of possible combinations to reach 0 is 1 (select nothing)
        dp[0] = 1;
        // int n = nums.size();

        for (int i=1; i<=target; i++) {
            // try every num in the nums array that can be the last num to reach i
            for (int num : nums) {
                if (dp[i]>INT_MAX) continue; // prevent overflow large sum
                // if num can be the last num to reach i, then we can look up dp table
                // and increase possible combination to i by dp[i-num], since i-num+num=i
                if (i - num >= 0) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};