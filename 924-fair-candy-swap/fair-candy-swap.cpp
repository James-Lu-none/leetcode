class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        set<int> bobSizeSet;
        int aliceSum = 0;
        for (int n:aliceSizes) aliceSum+=n;
        int bobSum = 0;
        for (int n:bobSizes) {
            bobSum+=n;
            bobSizeSet.insert(n);
        }
        // aliceSum + b - a = bobSum + a - b
        // => 2a-2b = aliceSum-bobSum
        // => a-b = (aliceSum-bobSum)/2
        // => a = (aliceSum-bobSum)/2 + b
        // => b = a - (aliceSum-bobSum)/2
        int diff = (aliceSum-bobSum)/2;
        for(int a:aliceSizes) {
            auto it = bobSizeSet.find(a-diff);
            if (it!=bobSizeSet.end()) {
                return {a,*it};
            }
        }
        return {0,0};
    }
};