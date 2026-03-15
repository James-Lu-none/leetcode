class Solution {
public:
    int recursiveSearch(vector<int>& nums, int target, int left, int right) {
        if (right<left) return -1;
        int mid = left + (right-left)/2;
        if (nums[mid] == target) return mid;
        return (nums[mid] < target)?recursiveSearch(nums, target, mid+1, right):recursiveSearch(nums, target, left, mid-1);
    }
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;
        return recursiveSearch(nums, target, left, right);
        while (right>=left) {
            // pratically use left + (right - left) / 2; instead of (left + right)/2 to avoid overflow
            int mid = left + (right - left) / 2;
            if (nums[mid] == target){
                return mid;
            } else if (nums[mid] > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return -1;
    }
};