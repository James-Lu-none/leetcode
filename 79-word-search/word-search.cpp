class Solution {
public:
    int m;
    int n;
    bool dfs(vector<vector<char>>& board, string word, int r, int c, int i){
        if (board[r][c]!=word[i]) return false;
        if (i == word.length()-1) return true;
        char temp = board[r][c];
        board[r][c] = '.';
        bool top = false, down = false, left = false, right = false;
        if(r-1>=0) top = dfs(board, word, r-1, c, i+1);
        if(r+1<m) down = dfs(board, word, r+1, c, i+1);
        if(c-1>=0) left = dfs(board, word, r, c-1, i+1);
        if(c+1<n) right = dfs(board, word, r, c+1, i+1);
        // backtrack: put original value back for next search 
        board[r][c] = temp;
        return top || down || left || right;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        
        // Start from fewer occurrences to reduce branches
        int firstCharCount = 0;
        int lastCharCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) firstCharCount++;
                if (board[i][j] == word.back()) lastCharCount++;
            }
        }
        if (lastCharCount < firstCharCount) {
            reverse(word.begin(), word.end());
        }

        for (int r=0;r<m;r++) {
            for (int c=0;c<n;c++) {
                if (dfs(board, word, r, c, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};