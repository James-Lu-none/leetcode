class Solution {
public:
    int n;
    // a dp table dp[i][j] to store the profit of bursting ballons from index i to j
    vector<vector<int>> dp{302, vector<int>(302, -1)};
    int solve(vector<int>& nums, int i, int j) {
		if(i > j) return 0;
        if(i == j){
            int temp = nums[i];
            if(i - 1 >= 0) temp *= nums[i - 1];
            if(i + 1 < n) temp *= nums[i + 1];
            return temp;
        }
		if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
		// For all elements in the range i to j, we choose all of them one by one 
		// to make them the last balloon to be burst. 
        int temp = 1;
        if(j + 1 < n) temp *= nums[j + 1]; // As balloon j + 1 will become adjacent to k after bursting  k + 1 to j balloons
        if(i - 1 >= 0) temp *= nums[i - 1]; // As balloon i- 1 will become adjacent to k after bursting  i  to k -1 balloons
        for(int k = i; k <= j; k++) {
            int a = temp;
		    // Burst the kth balloon after bursting (i, k - 1) and (k + 1, j) balloons
            a *= nums[k];
			// Recursively solve the left and right subproblems and add their contribution
            a += (solve(nums, i, k - 1) + solve(nums, k + 1, j));
			// If this choice of k yields a better answer
            ans = max(ans, a);
        }
        return dp[i][j] = ans;
    }
    int maxCoins(vector<int>& nums) {
        // if each time we butst the kth ballon as the first one to be busrst, the subproblems can be defined as solve(nums, i, k - 1) , solve(nums, k + 1, j), but the subproblem solve(nums, i, k - 1) and solve(nums, k + 1, j) are not independent since after bursting kth balloon, balloon k - 1 and k + 1 have become adjacent and they will need each other in order to calculate the profit.

        // so instead, we burst the kth balloon as the last one to be burst. the subproblems will become independent since (k - 1)th balloon and (k + 1)th balloon won't need each other in order to calculate the answer.
        vector<int> a = {1};
        for(int n: nums) a.push_back(n);
        a.push_back(1);
        n = a.size();
        return solve(a, 1, n-1-1);
    }
};