class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> res = {1};
        while (res.size() < N) {
            vector<int> tmp;
            // divide and conquer
            // odd part
            for (int i : res) if (i * 2 - 1 <= N) tmp.push_back(i * 2 - 1);
            // even part
            for (int i : res) if (i * 2 <= N) tmp.push_back(i * 2);
            /* 
            1
            |    \
            1     2
            |\    |\
            1 3   2 4 
            | |  /   \
            1 5 3  2  4 
            */    
            // for (int i : tmp) printf("%d ", i);
            // printf("\n");
            res = tmp;
        }
        return res;
    }
};