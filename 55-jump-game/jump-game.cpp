class Solution {
public:
    bool canJump(vector<int>& nums) {
        int near = 0, far = 0;
        while (far < nums.size() - 1) {
            int farthest = 0;
            // at here, [near, far] means all the possible steps i can be on after N jumps
            // so we iterate all selection and choose the farest one
            for (int i = near; i <= far; i++) {
                farthest = max(farthest, i + nums[i]);
            }
            if (farthest<=near) return false;

            // update next jump search range [near, far] 
            // with [far+1 (end of previous search range), farthest (next farthest jump possible)]
            near = far + 1;
            far = farthest;
        }
        return true;
    }
};