class Solution {
public:
    // two pointer with back tracking
    // worst time complexity O(MN), average O(M+N)
    // space complexity O(1)
    bool isMatch(string s, string p) {    
        int m = s.length();
        int n = p.length();
        int i = 0;
        int j = 0;
        int lastMatchPos = -1;
        // we only need to track the lastStarPos, since if last star can't match, then prior wont match neither
        int lastStarPos = -1;
        // the worst case for using backtracking is still O(MN), but its average O(M+N) if i and j aren't 
        // frequently backtracking
        // example that i and j frequently backtracking, where p has * with similar but different pattern as s
        // s: aaaaaaaaab (len=M)
        // p: *aaaaac (len=N)
        // at 1st iteration: lastStarPos = 0, j = 1, lastMatchPos = 0, i = 0, at this moment, * at lastStarPos matches 0 char
        // at 2nd iteration: lastStarPos = 0, j = 2, i = 1
        // at 3rd iteration: lastStarPos = 0, j = 3, i = 2
        // at nth iteration: loop: lastStarPos = 0, j = N, i = N-1, 'c' doesn't match 'a', so back track
        // => now let * at lastStarPos take 1 char, so lastMatchPos=1, i reset back to lastMatchPos=1, j reset back to lastStarPos+1=1 and  now
        // this will repeat at M times so worst case is O(MN)
        while (i<m) {
            if (j < n && (s[i] == p[j] || p[j] == '?')){
                i++;
                j++;
            }
            else if (j < n && p[j] == '*'){
                // update lastStarPos
                lastStarPos = j;
                j++;
                // update lastMatchPos with i, and we dont add i here since * can match 0 char
                // this is the starting point of back tracking
                lastMatchPos = i;
            }
            else if (lastStarPos != -1){
                // p[:i] doesn't match s[:j], try back tracking
                // let lastStartPos's * match 1 more chars
                j = lastStarPos + 1;
                // backtrack i to lastMatchPos+1
                lastMatchPos++;
                i = lastMatchPos;
            }
            else {
                // characters do not match
                // current pattern p[j] is not star
                // there was no * to backtrack
                return false;
            }
        }
        
        //check for remaining characters in pattern
        while (p[j] == '*' && j < n) j++;
        
        // ensure matching considers the entire pattern
        if (j == n) return true;
        else return false;
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