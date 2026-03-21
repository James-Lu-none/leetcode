class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        int counter = 0;
        for (int i = 0; i < n; i++) { // start
            int targetCount = 0;
            for (int j = i; j < n; j++) { // len
                if (nums[j] == target) targetCount++;
                else targetCount--;
                if (targetCount > 0) total++;
            }
        }
        return total;
    }
};