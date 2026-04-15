class Solution {
public:
    int rob(vector<int>& nums) {
        // rob[i-2], rob[i-1] and rob[i]
        int n = nums.size();
        if (n<=1) return nums[0];
        int robi_2 = nums[0];
        int robi_1 = max(nums[0], nums[1]);
        int robi = robi_1;
        for (int i=2; i<n; i++) {
            robi = max(robi_1, robi_2+nums[i]);
            robi_2 = robi_1;
            robi_1 = robi;
        }
        return robi;
    }
};