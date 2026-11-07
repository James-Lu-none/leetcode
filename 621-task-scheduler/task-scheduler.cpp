class Solution {
public:
    // int leastInterval(vector<char>& tasks, int n) {
    //     priority_queue<int, vector<int>, less<int>> pq;
    //     unordered_map<int, int> freq;
    //     for(char c: tasks) {
    //         freq[c-'A']++;
    //     }
    //     for (auto& pair : freq) {
    //         printf("%d, %d\n", pair.first, pair.second);
    //         pq.push(pair.second);
    //     }
    //     vector<int> work_items;
    //     int cycle_count = 0;
    //     while (!pq.empty()) {
    //         work_items.clear();
    //         for (int i=0; i<n+1; i++) {
    //             if (!pq.empty()) {
    //                 int max_val = pq.top();
    //                 pq.pop();
    //                 work_items.push_back(max_val-1);
    //             }
    //         }
    //         for (int w: work_items) {
    //             if (w!=0) {
    //                 pq.push(w);
    //             }
    //         }
    //         if(pq.empty()) {
    //             cycle_count += work_items.size();
    //         } else {
    //             cycle_count += (n+1);
    //         }
    //     }
    //     return cycle_count;
    // }
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int, int> freq;
        int max_freq = 0;
        for(char c: tasks) {
            freq[c-'A']++;
            max_freq = max(max_freq, freq[c-'A']);
        }

        // 2. 計算有多少個任務同時達到了最大頻率
        int max_freq_count = 0;
        for (int i = 0; i < 26; i++) {
            if (freq[i] == max_freq) {
                max_freq_count++;
            }
        }

        // 3. 套用公式
        int ans = (max_freq - 1) * (n + 1) + max_freq_count;

        // 4. 如果任務太多把空位撐爆了，答案就是任務總數
        return max((int)tasks.size(), ans);
    }
};