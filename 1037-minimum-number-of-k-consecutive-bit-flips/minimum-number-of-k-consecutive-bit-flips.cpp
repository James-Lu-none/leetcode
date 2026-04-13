class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int currFlips = 0;
        int ans = 0;
        vector<int> flipDiff(n+1, 0);
        for(int i = 0; i<n; i++) {
            // currFlips will affect all the following bits
            currFlips += flipDiff[i];
            // 0 with even flips or 1 with odd flips will result in 0, and we must flip when we see 0
            if ((currFlips+nums[i])%2 == 0) {
                if (i+k>n){
                    return -1;
                }
                ans++;
                currFlips++;
                // when we flip on i, we do currFlips++, and it will affect all the following bits
                // which is not what we want, so we have to eliminate its effect after flipping k bits
                // and we can do this by substracting 1 to currFlips at bit i+k
                flipDiff[i+k]--;
            }
        }
        return ans;
    }
};