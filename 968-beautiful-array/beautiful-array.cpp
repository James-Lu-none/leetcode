class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res = {1};
        while (res.size() < N) {
            vector<int> tmp;
            // Try to divide and conquer,
            // One way is to divide into [1, N / 2] and [N / 2 + 1, N].
            // But it will cause problems when we merge them.
            // Another way is to divide into odds part and evens part, so there is no k with A[k] * 2 = odd + even
            // odd part
            for (int i : res) if (i * 2 - 1 <= N) tmp.push_back(i * 2 - 1);
            // even part
            for (int i : res) if (i * 2 <= N) tmp.push_back(i * 2);
            /* 
            1
            |    \
            1     2
            |\    |\
            1 3   2 4 (1,3,2 creates 1,5,3 and 1,2 creates 2,4)
            |\|   | |
            | |\  / |
            | | \/  |
            | | /\  |
            1 5 3 2 4
            */    
            // for (int i : tmp) printf("%d ", i);
            // printf("\n");
            res = tmp;
        }
        return res;
    }
};