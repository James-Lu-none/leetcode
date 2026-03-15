class Solution {
public:
    // 傳統二元搜尋的搜尋對象: 數組中現有的索引 (Index)
    // 搜尋答案 (Binary Search on Answer)的搜尋對象: 滿足條件的數值 (Value)
    // 在現實問題中，我們常常不知道答案在哪裡，但我們知道答案在哪個範圍內，且具備單調性
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int size = piles.size();
        int right = 0;
        for (int p : piles) right = max(right, p);

        int ans = right;
        while (left <= right) {
            int mid = left + (right-left)/2;
            
            if (finishCheck(piles, h, mid)) {
                ans = mid;
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return ans;
    }
    bool finishCheck(vector<int>& piles, int h, int k) {
        long t = 0;
        for (int p : piles) {
            t += (p + k - 1) / (long)k; 
        }
        return t <= h;
    }
};