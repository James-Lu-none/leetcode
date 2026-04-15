class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        // this is a extend problem of House Robber (you can't steal adjacent house, what is the maximum value you can steal)
        // After picking nums[i], you must delete nums[i]-1 and nums[i]+1 elements
        int m = 0;
        vector<int> houses(10000+1);
        for (int num:nums) {
            houses[num]+=num;
            m = max(m,num);
        }
        // if you pick houses[i], you can't pick houses[i-1] and houses[i+1]
        // houses index start from 1, so i start from 2, if steal houses[2], houses[1] and houses[3] will be ignored, i will jump to 4
        // if dont steal houses[2], then houses[1] and houses[3] is taken,
        // rob[i] means maximum amount of money we can steal from first house to house i 
        // it will be assigned to rob[i-1] if dont take house[i]; rob[i-2]+house[i] if takes house[i] (removing the effect of taking house[i-1]) 
        
        // // space complexity: O(10001), still O(1) but we can use temp to make it smaller
        // vector<int> rob(m+1);
        // rob[0] = houses[0];
        // rob[1] = max(houses[0], houses[1]);
        // for(int i=2; i<m+1; i++) {
        //     rob[i] = max(rob[i-1], houses[i]+rob[i-2]);
        // }
        // return rob[m];
        
        // only rob[i-2], rob[i-1] and rob[i] is needed
        // -> robi_2, robi_1, robi
        int robi_2 = houses[0];
        int robi_1 = max(houses[0], houses[1]);
        int robi = robi_1;
        for(int i=2; i<=m; i++) {
            robi = max(robi_1, houses[i]+robi_2);
            robi_2 = robi_1;
            robi_1 = robi;
        }
        return robi;
    }
};