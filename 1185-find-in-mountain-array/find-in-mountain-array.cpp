/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int left = 0;
        int right = n-1;
        int ans = -1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        int peakIndex = left;
        printf("peak at %d\n", peakIndex);
        left = 0;
        right = peakIndex;
        while (left<=right) {
            int mid = left + (right-left)/2;
            int midVal = mountainArr.get(mid);
            printf("left: %d, mid: %d, right: %d\n", left, mid, right);
            if (midVal == target) {
                return mid;
            } else if (midVal > target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        if (ans != -1) return ans;
        printf("left side not found, starting at right \n");
        left = peakIndex+1;
        right = n-1;
        while (left<=right) {
            int mid = left + (right-left)/2;
            int midVal = mountainArr.get(mid);
            printf("left: %d, mid: %d, right: %d\n", left, mid, right);
            if (midVal == target) {
                return mid;
            } else if (midVal < target) {
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans;
        
    }
};