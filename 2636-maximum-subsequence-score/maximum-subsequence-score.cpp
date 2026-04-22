class Solution {
public:
    // same as 1383. Maximum Performance of a Team (Hard)
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> ess;
        for (int i = 0; i<nums1.size(); i++) ess.push_back({nums2[i], nums1[i]});
        sort(ess.rbegin(), ess.rend());
        long long sumOfSpeed = 0;
        long long result = 0;
        priority_queue<int, vector<int>, greater<int>> pq; // min-heap
        // although problem says we have to pick subsequence
        // but the problem didn't told us to return the exact subsequence we choose, so it doesn't matter that how we choose from nums1
        for (auto it: ess) {
            int efficiency = it.first;
            int speed = it.second;
            sumOfSpeed+=(long long)speed;
            pq.emplace(speed);
            if (pq.size()>k) {
                sumOfSpeed-=pq.top();
                pq.pop();
            }
            if (pq.size()==k) result = max(result, sumOfSpeed*(long long)efficiency);
        }
        return result;
    }
};