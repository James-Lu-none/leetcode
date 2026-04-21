class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.length();
        if (s[n - 1] != '0') return false;

        queue<int> q;
        q.push(0);
        
        int farthest_scanned = 0;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            // 下一步的搜尋區間
            int start = max(curr + minJump, farthest_scanned + 1);
            int end = min(curr + maxJump, n - 1);

            for (int i = start; i <= end; i++) {
                if (s[i] == '0') {
                    if (i == n - 1) return true;
                    q.push(i);
                }
            }
            // update scanned range
            farthest_scanned = max(farthest_scanned, end);
        }

        return false;
    }
};