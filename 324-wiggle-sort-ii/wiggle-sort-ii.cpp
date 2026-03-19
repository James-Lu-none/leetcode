class Solution {
public:
    // return nth largest element value in the vector
    int quickSelect(vector<int>& nums, int nth_element) {
        int low = 0;
        int high = nums.size()-1;
        while (low <= high) {
            int pivot = high;
            int i=low;
            for (int j=low;j<high;j++) {    
                if (nums[j]<nums[pivot]){
                    swap(nums[i], nums[j]);
                    i++;
                }
            }
            swap(nums[i], nums[pivot]);
            if (i == nth_element) {
                return nums[i];
            } else if (i > nth_element) {
                high = i-1;
            } else {
                low = i+1;
            }
        }
        return -1;
    }
    
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        int mid = quickSelect(nums, n/2);
        // printf("%d\n", mid);

        int low = 0;
        int i = 0;
        int high = n-1;
        // use Dutch National Flag (3-way partitioning) // 跟mid比
        #define A(i) nums[(1 + 2 * (i)) % (n | 1)]
        while (i <= high) {
            if (A(i)>mid) {
                swap(A(low), A(i));
                low++;
                i++;
            } else if (A(i)<mid) {
                swap(A(i), A(high));
                high--;
            } else {
                i++;
            }
        }
        // while (low <= high) {
        //     if (nums[low]>mid) {
        //         swap(nums[low], nums[i]);
        //         low++;
        //         i++;
        //     } else if (nums[i]<mid) {
        //         swap(nums[i], nums[high]);
        //         high--;
        //     } else {
        //         i++;
        //     }
        // }
    }
};