class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> mp;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            auto it = mp.find(target-nums[i]);
            if (it != mp.end())
            {
                return {i, it->second}; 
            }
            else {
                mp[nums[i]] = i;
            }
        }
        return {0,0};
    }
};