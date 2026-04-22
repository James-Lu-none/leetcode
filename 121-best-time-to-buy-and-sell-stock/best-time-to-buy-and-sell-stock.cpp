class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> diff(n,0);
        for (int i=1; i<n; i++) {
            diff[i-1] = prices[i] - prices[i-1];
        }
        return maxSumOfSubarray(diff, 0, n-1);
    }
    int maxSumOfSubarray(vector<int>& diff, int low, int high) {
        if (low>=high) return diff[low];
        int mid = low + (high-low)/2;
        int leftMax = maxSumOfSubarray(diff, low, mid);
        int rightMax = maxSumOfSubarray(diff, mid+1, high);
        int crossMax = maxSumOfSubarrayCross(diff, low, mid, high);
        return max(leftMax, max(rightMax, crossMax));
    }
    int maxSumOfSubarrayCross(vector<int>& diff, int low, int mid, int high) {
        int leftSum = INT_MIN;
        int rightSum = INT_MIN;
        int sum;

        sum = 0;
        for (int i=mid; i>=low; i--) {
            sum+=diff[i];
            leftSum = max(leftSum, sum);
        }
        sum = 0;
        for (int i=mid+1; i<=high; i++) {
            sum+=diff[i];
            rightSum = max(rightSum, sum);
        }
        return rightSum+leftSum;
    }
};