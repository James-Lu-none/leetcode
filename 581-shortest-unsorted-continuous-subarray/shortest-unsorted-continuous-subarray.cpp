class Solution {
public:
int findUnsortedSubarray(std::vector<int>& nums) {
        int n = nums.size();
        int max_val = INT_MIN;
        int min_val = INT_MAX;
        
        int right = -1;
        int left = -1;

        // Left-to-right pass to find the rightmost boundary
        for (int i = 0; i < n; ++i) {
            if (max_val > nums[i]) {
                // Out of order relative to the maximum seen so far
                right = i;
            } else {
                max_val = nums[i];
            }
        }

        // Right-to-left pass to find the leftmost boundary
        for (int i = n - 1; i >= 0; --i) {
            if (min_val < nums[i]) {
                // Out of order relative to the minimum seen so far
                left = i;
            } else {
                min_val = nums[i];
            }
        }

        // If 'right' was never updated, the array is already fully sorted
        if (right == -1) {
            return 0;
        }

        // Return the continuous length
        return right - left + 1;
    }
};