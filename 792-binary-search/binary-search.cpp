class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        vector<int> sub_vector(nums);
        while (true){
            int n = sub_vector.size();
            int mid = n/2 + low;
            int mid_value = nums[mid];
            // printf("before %d %d, %d, %d \n", n ,mid, low, high);
            if (mid_value == target) {
                return mid;
            } else if (target < mid_value) {
                high = mid-1;
            } else {
                low = mid+1;
            }
            if(high<0) return -1;
            if(low>high) return -1;
            // printf("after %d %d, %d, %d \n", n ,mid, low, high);
            sub_vector = vector<int>(nums.begin()+low, nums.begin()+high);
        }
        return -1;
    }
};