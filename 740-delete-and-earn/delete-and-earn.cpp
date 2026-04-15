class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // this is a extend problem of House Robber (you can't steal adjacent house, what is the maximum value you can steal)
        // After picking nums[i], you must delete nums[i]-1 and nums[i]+1 .elements
        int m = 1;
        vector<int> houses(10000+1);
        for (int num:nums) {
            houses[num]+=num;
            m = max(m,num);
        }
        // if you pick houses[i], you can't pick houses[i-1] and houses[i+1]
        // houses index start from 1, so i start from 2, if steal houses[2], houses[1] and houses[3] will be ignored, i will jump to 4
        // if dont steal houses[2], then houses[1] and houses[3] is taken,
        // rob[i] means maximum amount of money we can steal from first house to house i 
        // it will be assigned rob[i-1] if dont take house[i], and rob[i-2]+house[i] if takes house[i] (removing the effect of taking house[i-1]) 
        vector<int> rob(m+1);

        // for(int i=0; i<m+1; i++) {
        //     printf("%d ",houses[i]);
        // }
        // printf("\n");
        rob[0] = houses[0];
        rob[1] = max(houses[0], houses[1]);
        for(int i=2; i<m+1; i++) {
            rob[i] = max(rob[i-1], houses[i]+rob[i-2]);
        }
        return rob[m];
    }
};