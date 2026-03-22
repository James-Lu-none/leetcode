class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int right = 0; right < n; right++) {
            set<int> odd, even;
            // left = r-1~0
            for (int left = right; left >= 0; left--) {
                if (nums[left]%2 == 0) even.insert(nums[left]);
                else odd.insert(nums[left]);

                if (odd.size() == even.size()) {
                    ans = max(ans, right-left+1);
                }
            }
        }
        return ans;
    }
};