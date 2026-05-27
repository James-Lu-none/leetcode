class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int result = 0;
        size_t i = 0;

        // smallest sum that cannot be formed 
        long long miss = 1;

        // If you can't make exact change for a particular amount "miss",
        // it indicates you lack a coin of value less than or equal to miss. 
        // To fill this gap, you add a coin of that exact missing amount
        // This addition allows you to now cover new amounts up to 2 * miss

        while (miss <= n) {
            if (i < nums.size() && nums[i] <= miss) {
                // update smallest sum that cannot be formed
                miss += nums[i];
                i++;
            } else {
                // greadly uses miss to patch array since it will update coverage from miss to 2*miss
                miss = miss*2;
                result++;
            }
        }

        return result;
    }
};