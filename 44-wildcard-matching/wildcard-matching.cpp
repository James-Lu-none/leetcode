class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length();
        int n = p.length();
        int i = 0;
        int j = 0;
        int lastMatchPos = -1;
        int lastStarPos = -1;
        while (i<m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')){
                i++;
                j++;
            }
            else if (j < n && p[j] == '*'){
                // every time when a star exist, add 
                lastStarPos = j;
                j++;
                lastMatchPos = i;
            }
            else if (lastStarPos != -1){
                j = lastStarPos + 1;
                //
                lastMatchPos++;
                i = lastMatchPos;
            }
            else {
                // characters do not match
                // current pattern p[j] is not star
                // last patter pointer was not *
                return false;
            }
        }
        
        //check for remaining characters in pattern
        while (p[j] == '*' && j < n) j++;
        return j == n;
    }

    // solve with dynamic programming, space and time complexity is O(MxN) 
    // bool isMatch(string s, string p) {
    //     int m = s.length();
    //     int n = p.length();
    //     vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
    //     dp[0][0] = true; // first must be true, empty matches empty;
        
    //     // init row 0: dp[0][j] and col 0: dp[i][0]
    //     // col 0 is already complete, empty pattern wont match anything
    //     // handle row 0, where s is empty, we dont have to check conditions other then p[j-1]=='*', since other pattern wont match empty s
    //     for (int j=1;j<n+1;j++){
    //         if(p[j-1]=='*') {
    //             dp[0][j] = dp[0][j-1];
    //         }
    //     }

    //     for (int i=1;i<m+1;i++){
    //         for (int j=1;j<n+1;j++) {
    //             if(p[j-1]=='*') {
    //                 // see if up or left is true
    //                 // if dp[i-1][j] is true means p[:j-1] matches s[:i-2], so if p[j-1] is '*' then p[:j-1] must match s[:i-1], this case means p[j-1] is matching 1 or more chars
    //                 // if dp[i][j-1] is true means p[:j-2] matches s[:i-1], so if p[j-1] is '*' then p[:j-1] must match s[:i-1], this case means p[j-1] is matching 0 chars (empty)
    //                 dp[i][j] = dp[i-1][j] | dp[i][j-1];
    //             }

    //             if(p[j-1]=='?' | p[j-1]==s[i-1]) {
    //                 // see if up left is true
    //                 // if dp[i-1][j-1] is true means that ? or charator match will make dp[i][j] match too
    //                 dp[i][j] = dp[i-1][j-1];
    //             }
    //         }
    //     }
    //     return dp[m][n];
    // }
};