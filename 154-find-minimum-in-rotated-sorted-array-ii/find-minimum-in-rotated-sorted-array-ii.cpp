class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==nums[high]){
                high--;
            }else if(nums[mid]>nums[high]){
                low=mid+1;
            }else if(nums[mid]<nums[high]){
                high=mid;
            }
        }
        printf("%d\n", low);
        return nums[low];

        // find rotate time k, then minimum is at k
        // find if there is any reverse, if there's any reverse, return num[k], else, return nums[0]
        // int n = nums.size();
        // int low = 0;
        // int high = n;

        // while(low < high) {
        //     int mid = low + (high-low)/2;
        //     for (int i = low; i<high-1; i++) {
        //         if (nums[i]>nums[i+1]) {
        //             return nums[i+1];
        //         }
        //     }
        //     high = mid-1;
        // }        
        // return nums[0];
    }
};