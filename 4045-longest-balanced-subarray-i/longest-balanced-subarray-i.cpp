class Solution {
public:
    // int longestBalanced(vector<int>& nums) {
    //     int n = nums.size();
    //     int ans = 0;
    //     for (int right = 0; right < n; right++) {
    //         set<int> odd, even;
    //         // left = r-1~0
    //         for (int left = right; left >= 0; left--) {
    //             if (nums[left]%2 == 0) even.insert(nums[left]);
    //             else odd.insert(nums[left]);

    //             if (odd.size() == even.size()) {
    //                 ans = max(ans, right-left+1);
    //             }
    //         }
    //     }
    //     return ans;
    // }
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        vector<int> lastPos(100000 + 1, -1); // 1 <= nums[i] <= 10^5, all element set to -1
        vector<int> A(n);
        // r 指向 nums 最後一個元素
        // 然後從 r 開始，一步一步往前走
        // 紀錄一個陣列 A[i]，for 每一個 i，如果 nums[i] 是偶數，則 A[i] 就設為 1; 如果 nums[i] 是奇數，則 A[i] 就設為 -1
        // 如果 lastPos[nums[i]] 是 -1 則把 i 存入 lastPos[nums[i]]，如果 lastPos[nums[i]] 是 n (!= -1)，則把 A[lastPos[nums[i]]] 改為 0
        int ans = 0;
        for (int r = 0; r<n; r++) {
            A[r] = (nums[r]%2==0)?1:-1;
            if (lastPos[nums[r]] != -1) {
                A[lastPos[nums[r]]] = 0;
            }                
            lastPos[nums[r]] = r;
            int sum = 0;
            for (int l = r;l >= 0;l--) {
                sum += A[l];
                if (sum == 0) {
                    ans = max(ans, r-l+1);
                }
            }
        }
        return ans;
    }
};