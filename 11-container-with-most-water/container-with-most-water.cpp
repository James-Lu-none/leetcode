class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0;
        int j = n-1;
        int ans = 0;
        while (i!=j) {
            int hi=height[i];
            int hj=height[j];
            ans = max(ans, (j-i)*min(hi,hj));
            if(hi>hj) j--;
            else i++;
        }
        return ans;
    }
};