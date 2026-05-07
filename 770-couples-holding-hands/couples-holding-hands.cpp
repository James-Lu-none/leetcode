class Solution {
public:
    // the following is the solution of N integers problem 
    // which contains integers from 0 up to N-1 but in random order
    // and can need to swap two number and swap them
    // what is the min swap to have i == row[i] (equivalently, sort the array) 
    // int minSwapsCouples(vector<int>& row) {
    //     int ans = 0;
    //     int n = row.size();
    //     
    //     // here utilize cyclic swapping algorithm
    //     // row: 2, 3, 1, 0, 5, 4
    //     // idx: 0, 1, 2, 3, 4, 5
    //     // calculate value at index i should be at index j, i --> j
    //     // we will obtain to cyclic index group
    //     // 0 --> 2, 2 --> 1, 1 --> 3, 3 --> 0 (back to 0)
    //     // 4 --> 5, 5 --> 4 (back to 4)
    //     // then we can swap row[i] with row[j] until i==j
    //     for (int i = 0; i < n; i++) {
    //         for (int j = row[i]; i != j; j = row[i]) {
    //             swap(row[i], row[j]);
    //             ans++;
    //         }
    //     }
    //     return ans;
    // }

    // by extending N integers problem
    // instead of i == row[i], we require i == partner[pos[partner[row[i]]]]
    // 
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        int n = row.size();

        vector<int> partner(n);
        vector<int> pos(n);
        
        for (int i = 0; i < n; i++) {
            partner[i] = (i % 2 == 0 ? i + 1 : i - 1);
            pos[row[i]] = i;
        }
        
        for (int i = 0; i < n; i++) {
            for (int j = partner[pos[partner[row[i]]]]; i != j; j = partner[pos[partner[row[i]]]]) {
                swap(row[i], row[j]);
                swap(pos[row[i]], pos[row[j]]);
                ans++;
            }
        }
        return ans;
    }
};