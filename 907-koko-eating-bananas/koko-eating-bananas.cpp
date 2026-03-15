class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 0;
        for (int p : piles) right = max(right, p); // 找出最大堆

        int ans = right;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // 驗證「目前猜的這個速度 mid」是否能在 h 內吃完
            if (finishCheck(piles, h, mid)) {
                ans = mid;      // 記錄可能的答案
                right = mid - 1; // 速度可行，試試看能不能更慢
            } else {
                left = mid + 1;  // 太慢了，必須加快速度
            }
        }
        return ans;
    }

    bool finishCheck(vector<int>& piles, int h, int k) {
        if (k == 0) return false; // 防止除以 0 的保險
        long t = 0;
        for (int p : piles) {
            // 使用整數向上取整公式：(p + k - 1) / k
            t += (p + k - 1) / (long)k; 
        }
        // 如果花費時間 t 小於等於 h，代表速度夠快
        return t <= h;
    }
};