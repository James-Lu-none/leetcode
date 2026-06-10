class Solution {
public:
    int findFirstGreater(const vector<int>& arr2, int target) {
        int left = 0;
        int right = arr2.size() - 1;
        int ans = -1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr2[mid] > target) {
                ans = arr2[mid];
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        // sort arr2 and make elements unique since we will binary search it later
        sort(arr2.begin(), arr2.end());
        arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
        // dp[i][j] stores the minimum possible value of the last element after processing arr1[0..i] to be strictly increasing with j replacements
        // init with INT_MAX as it is unreachable
        vector<vector<int>> dp(n, vector<int>(n + 1, INT_MAX));
        // actually we can achieve space complexity O(N) since memory before i-1 is not relevent any more, but it will add switching costs
        
        // Base case:
        dp[0][0] = arr1[0]; // not replacing at i=0
        dp[0][1] = arr2[0]; // replacing with min value of arr2 at i=0
        
        // bottom up dp
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i + 1; j++) {
                
                // Case 1: do not replace arr1[i].
                // If arr1[i] can be appended to a valid increasing sequence,
                // the new ending value becomes arr1[i]. unless it remain INF (unreachable)
                if (dp[i-1][j] < arr1[i])
                {
                    dp[i][j] = arr1[i];
                }
                
                // case 2: try perform an additional operation
                // we only care about the condition where the possible minimum value of the last step is not INF
                // since if it is INF (unreachable), then there's no point to try it on current step
                if (j > 0 && dp[i-1][j-1] != INT_MAX) {
                    // find the first value that is greater than the possible minimum value of the last step 
                    int next_val = findFirstGreater(arr2, dp[i-1][j-1]);
                    if (next_val != -1) {
                        dp[i][j] = min(dp[i][j], next_val);
                    }
                }
            }
        }
        // ex: arr1 = [1, 5, 3, 6, 7], arr2 = [1, 2, 3, 4]
        // i:num[i]\j: 0, 1, 2, 3, 4, 5
        //        0:1  1, 1, x, x, x, x
        //        1:5  5, 2, 2, x, x, x
        //        2:3  x, 3, 3, 3, x, x
        //        3:6  x, 6, 6, 6, x, x
        //        4:7  x, 7, 7, 7, x, x
        // find the first colume that is not inf in the last row dp[n-1]
        // that is, finding the least minimum number of operations needed to make arr1 strictly increasing.
        for (int j = 0; j <= n; ++j) {
            if (dp[n-1][j] != INT_MAX) {
                return j;
            }
        }
        return -1;
    }
};