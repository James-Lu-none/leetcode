class Solution {
public:
    int M;
    unordered_map<int, int> mapping;
    Solution(int n, vector<int>& blacklist) {
        int B = blacklist.size();
        // for n = 7
        // blacklist = [2,3,5]
        // M = 4 means that our built-in random function only need to generate a random number from 0 to 3
        M = n - B;
        
        // put blacklist in a hash table to check if x exist in blacklist in O(1)
        // inserting one blacklist value takes O(1), inserting all takes O(n)
        unordered_set<int> black_set(blacklist.begin(), blacklist.end());

        // find whiteValue in range [M, n-1] to replace the value in bloack
        int whiteValue = n - 1;
        for (int b : blacklist) {
            // we only need to map away black values in [0, M-1] to a white value in [M, n-1], since out
            // since our generated random number is in [0, M-1]
            if (b >= M) continue;

            // find a value that can be the replacement for b
            while (black_set.count(whiteValue)) {
                whiteValue--;
            }
            
            // mapping[2] => 6
            // mapping[3] => 4
            mapping[b] = whiteValue;
            whiteValue--;
        }
    }
    
    int pick() {
        int r = rand() % M;
        if (mapping.count(r)) {
            return mapping[r];
        }
        return r;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */