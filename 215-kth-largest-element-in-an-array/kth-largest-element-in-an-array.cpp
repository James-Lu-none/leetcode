class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        return solve(nums, nums.size() - k + 1);
    }
    void findMediums(vector<int>& nums, vector<int>& mediums){
        for (int i=0; i<nums.size()-5; i+=5)
        {
            sort(nums.begin() + i, nums.begin() + i+5);
            mediums.push_back(nums[i+2]);
        }
    }
    int solve(vector<int>& nums, int k) {
        if (nums.size() <= 5) {
            sort(nums.begin(), nums.end());
            return nums[k - 1];
        }
        vector<int> mediums;
        for (int i = 0; i < nums.size(); i += 5) {
            auto it_end = (nums.size() - i >= 5) ? nums.begin() + i + 5 : nums.end();
            vector<int> group(nums.begin() + i, it_end);
            sort(group.begin(), group.end());
            mediums.push_back(group[group.size() / 2]);
        }
        int pivot = solve(mediums, (mediums.size() + 1) / 2);
        vector<int> s1,s2,s3;
        for (int num:nums) {
            if (num<pivot) s1.push_back(num);
            else if (num>pivot) s3.push_back(num);
            else s2.push_back(num);
        }
        if (s1.size()>=k) return solve(s1, k);
        else if (s1.size()+s2.size()>=k) return s2[0];
        else return solve(s3, k-(s1.size()+s2.size()));
    }
};