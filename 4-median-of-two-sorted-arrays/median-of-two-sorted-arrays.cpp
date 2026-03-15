class Solution {
public:
    double recursive(vector<int>& nums1, vector<int>& nums2, int left, int right, int halfLen, int n, int m) {
        if (right<left) return 0.0;

        int i = left + (right - left) / 2;
        int j = halfLen - i;

        // set INT_MIN/INT_MAX if reaches end
        int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRight1 = (i == n) ? INT_MAX : nums1[i];
        int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRight2 = (j == m) ? INT_MAX : nums2[j];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            if ((n + m) % 2 == 0) {
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else {
                return max(maxLeft1, maxLeft2);
            }
        }

        if (maxLeft1 > minRight2) return recursive(nums1, nums2, left, i-1, halfLen, n, m);
        else return recursive(nums1, nums2, i+1, right, halfLen, n, m);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) return findMedianSortedArrays(nums2, nums1);

        int n = nums1.size();
        int m = nums2.size();
        
        int left = 0, right = n;
        int halfLen = (n + m + 1) / 2;

        // return recursive(nums1, nums2, left, right, halfLen, n, m);

        while (left <= right) {
            int i = left + (right - left) / 2;
            int j = halfLen - i;

            // set INT_MIN/INT_MAX if reaches end
            int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
            int minRight1 = (i == n) ? INT_MAX : nums1[i];
            int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
            int minRight2 = (j == m) ? INT_MAX : nums2[j];

            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((n + m) % 2 == 0) {
                    return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
                } else {
                    return max(maxLeft1, maxLeft2);
                }
            }
            // binary search logic here
            else if (maxLeft1 > minRight2) {
                right = i - 1;
            } 
            else {
                left = i + 1;
            }
        }
        return 0.0;
    }
};