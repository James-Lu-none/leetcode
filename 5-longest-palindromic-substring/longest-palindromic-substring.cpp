class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }
        
        int max_len = 1;
        int start = 0;
        int end = 0;
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        // the table dp was used to avoid unnecessary re-computation
        // the bool value of dp[j][i] holds whether [j...i] is a palindrome or not
        // ex: "babad"
        //    b  a  b  a  d
        // b  T  -  T  -  -
        // a  x  T  -  T  -
        // b  x  x  T  -  -
        // a  x  x  x  T  -
        // d  x  x  x  x  T
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (s[i] != s[j]) continue;
                // here we have character i == character j
                // so if i-j <= 2, we can state that s[j...i] is a palindrome without checking the table dp since
                // (1) i-j = 0, its a single character, and every single character is a palindrome with length 1
                // (2) i-j = 1, its a string with length 2, and char i == char j, so it is a even palindrome with length 2
                // (3) i-j = 2, its a string with length 3, and char i == char j, so no matter what charater is between, it is a palindrome with length 3
                // and for i-j > 2 means its a string with length >= 4, we check the table dp[j + 1][i - 1]
                // if s[j+1...i-1] is palindrome, then s[j...i] must be a palindrome too, since again char i == char j
                // [j, j+1 .... i-1, i]
                //      v        v
                // [x, [palindrome], x]
                if (i - j <= 2 || dp[j + 1][i - 1]) {
                    dp[j][i] = true;
                    if (i - j + 1 > max_len) {
                        max_len = i - j + 1;
                        start = j;
                        end = i;
                    }
                }
            }
        }
        
        return s.substr(start, end - start + 1);
    }
};