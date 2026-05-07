class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[0][0] = true; // first must be true, empty matches empty;
        
        // clear the row 0, where s is empty
        for (int j=1;j<n+1;j++){
            if(p[j-1]=='*') {
                dp[0][j] = dp[0][j-1];
            }
        }

        for (int i=1;i<m+1;i++){
            for (int j=1;j<n+1;j++) {
                if(p[j-1]=='*') {
                    // if dp[i-1][j] is true means p[:j-1] matches s[:i-2], so if p[j-1] is '*' then p[:j-1] must match s[:i-1]
                    // if dp[i][j-1] is true means p[:j-1] matches s[:i-2], so if p[j-1] is '*' then p[:j-1] must match s[:i-1] 
                    dp[i][j] = dp[i-1][j] | dp[i][j-1];
                }
                if(p[j-1]=='?') {
                    dp[i][j] = dp[i-1][j-1];
                }
                if(p[j-1]==s[i-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
            }
        }
        return dp[m][n];
    }
};