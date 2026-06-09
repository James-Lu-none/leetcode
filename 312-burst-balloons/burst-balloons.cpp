class Solution {
public:
    int n;
    // a dp table dp[i][j] to store the profit of bursting ballons from index i to j
    vector<vector<int>> dp{302, vector<int>(302, -1)};
    // this function solves finds the last balloon that should be burst by iterate all balloons and return the largest
    int solve(vector<int>& nums, int i, int j) {
		if (i + 1 >= j) return 0;
		if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
		// For all balloon in the range i+1 to j-1, iterate all possible k as the last balloon to be burst.
        for(int k = i+1; k < j; k++) {
		    // Burst the kth balloon after bursting (i, k - 1) and (k + 1, j) balloons
            int coins = nums[i] * nums[k] * nums[j];
            int total = coins + solve(nums, i, k) + solve(nums, k, j);
			// If this choice of k yields a better answer
            ans = max(ans, total);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        // if each time we butst the kth ballon as the first one to be burst, the subproblems can be defined as solve(nums, i, k - 1) , solve(nums, k + 1, j), but the subproblem solve(nums, i, k - 1) and solve(nums, k + 1, j) are not independent since after bursting kth balloon, balloon k - 1 and k + 1 have become adjacent and they will need each other in order to calculate the profit.

        // so instead, we burst the kth balloon as the last one to be burst. the subproblems will become independent since (k - 1)th balloon and (k + 1)th balloon won't need each other in order to calculate the answer.
        vector<int> a = {1};
        for(int n: nums) a.push_back(n);
        a.push_back(1);
        n = a.size();
        return solve(a, 0, n-1);
    }
};