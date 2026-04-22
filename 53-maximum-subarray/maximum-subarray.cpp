class Solution {
public:
    int maxSubArray(vector<int>& nums) {    
        // return solve(nums, 0, false); // without dp

        vector<vector<int>> dp(2, vector<int>(nums.size(), INT_MIN));
        return solve(nums, 0, false, dp); // with dp
    }
    int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {
		// our subarray must contain atleast 1 element. If mustPick is false at end means no element is picked and this is not valid case
        if(i >= size(A)) return mustPick ? 0 : INT_MIN;
        if(dp[mustPick][i]!=INT_MIN) return dp[mustPick][i]; // return the memory if we already calculated it before
        if(mustPick)
            return dp[mustPick][i] = max( // create one branch only, return the bigger one
                0, // 1. not choose current element stop here (add 0 to sum and stop recurse)
                A[i] + solve(A, i+1, true, dp) // 2. choose current element and keep recurse (add A[i] to sum and keep recurse)
            );
            // at layer k, we compare 
        else {
            return dp[mustPick][i] = max( // create two branch here, return the bigger one
                solve(A, i+1, false, dp), // 1. not choosing current element i, so next element (i+1) is not must choose
                A[i] + solve(A, i+1, true, dp) // 2. chose current element i, so we must choose next element (i+1)
            );
        }
    }
    // int solve(vector<int>& A, int i, bool mustPick) {
	// 	// our subarray must contain atleast 1 element. If mustPick is false at end means no element is picked and this is not valid case
    //     if(i >= size(A)) return mustPick ? 0 : INT_MIN;       
    //     if(mustPick)
    //         return max( // create one branch only, return the bigger one
    //             0, // 1. not choose current element stop here (add 0 to sum and stop recurse)
    //             A[i] + solve(A, i+1, true) // 2. choose current element and keep recurse (add A[i] to sum and keep recurse)
    //         );
    //         // at layer k, we compare 
    //     else {
    //         return max( // create two branch here, return the bigger one
    //             solve(A, i+1, false), // 1. not choosing current element i, so next element (i+1) is not must choose
    //             A[i] + solve(A, i+1, true) // 2. chose current element i, so we must choose next element (i+1)
    //         );
    //     }
    // }
};
