class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int n = mat.size();
        int m = mat[0].size();
        for(int i = 0; i < n;i++){
            for(int j = 0; j < m; j++){
                if(mat[i][(j+k)%m] != mat[i][j]){
                    return false;
                }
            }
        }
        return true;
    }
    // void reverse(vector<int>& v, int l, int r) {
    //     while (l<r) {
    //         swap(v[l++], v[r--]);
    //     }
    // }
    // void leftRotate(vector<int>& v, int n, int k) {
    //     if (n<=1) return;
    //     k %= n;
    //     reverse(v, 0, k-1);
    //     reverse(v, k, n-1);
    //     reverse(v, 0, n-1);
    // }
    // void rightRotate(vector<int>& v, int n, int k) {
    //     if (n<=1) return;
    //     k %= n;
    //     reverse(v, 0, n-1);
    //     reverse(v, 0, k-1);
    //     reverse(v, k, n-1);
    // }
    // bool areSimilar(vector<vector<int>>& mat, int k) {
    //     int row = 0, col = 0;
    //     int n = mat.size();
    //     int m = mat[0].size();
    //     auto matO(mat);
    //     for (int i = 0; i < n; i++) {
    //         if (i%2==0){
    //             leftRotate(mat[i], m, k);
    //             if (matO[i]!=mat[i]) return false;
    //         } else {
    //             rightRotate(mat[i], m, k);
    //             if (matO[i]!=mat[i]) return false;
    //         }
    //     }
    //     return true;
    // }
};