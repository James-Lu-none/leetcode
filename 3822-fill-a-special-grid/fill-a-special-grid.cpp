class Solution {
public:
    //      col0 col1
    // row0
    // row1
    int counter = 0;
    void solve(vector<vector<int>>& A, int colLow, int colHigh, int rowLow, int rowHigh) {
        int size = rowHigh - rowLow;
        if (size == 1) { // its always a square so we dont have to check col
            A[rowLow][colLow] = counter;
            counter++;
            return;
        }
        int rowMid = rowLow + size/2;
        int colMid = colLow + size/2;
        solve(A, colMid, colHigh, rowLow, rowMid);
        solve(A, colMid, colHigh, rowMid, rowHigh);
        solve(A, colLow, colMid, rowMid, rowHigh);
        solve(A, colLow, colMid, rowLow, rowMid);
        return;
    }
    vector<vector<int>> specialGrid(int n) {
        int size = 1 << n;
        vector<vector<int>> grid(size, vector<int>(size));
        solve(grid, 0, size, 0, size);
        return grid;
    }
};