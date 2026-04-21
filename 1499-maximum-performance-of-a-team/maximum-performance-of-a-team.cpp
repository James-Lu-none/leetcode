class Solution {
public:
    // core fix minimum efficiency and find maximum speeds
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int, int>> ess(n);
        for (int i = 0; i < n; ++i) ess.emplace_back(efficiency[i], speed[i]);
        // first sort engineers by {efficiency, speed}, so every time we pick
        // we wont get engineer with efficiency that is larger then before
        sort(rbegin(ess), rend(ess));
        long sumOfSpeed = 0, result = 0;
        priority_queue <int, vector<int>, greater<int>> pq; //min heap
        for(auto it: ess){
            int efficiency = it.first;
            int speed = it.second;
            // add current one
            pq.emplace(speed);
            sumOfSpeed += speed;
            // kick the one with slowest speed if reached max # of pick
            if (pq.size() > k) {
                sumOfSpeed -= pq.top();
                pq.pop();
            }
            result = max(result, sumOfSpeed * efficiency);
        }
        return result % (int)(1e9+7);
    }
};