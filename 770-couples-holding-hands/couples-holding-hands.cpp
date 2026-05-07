class Solution {
public:
    // greedy 
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        int n = row.size();
        vector<int> pos(n);

        // record the position of value i in row 
        for (int i = 0; i < n; i++) {
            pos[row[i]] = i;
        }

        // greedy: check every two index, if row[i] and row[i+1] aren't partner, then swap immediately
        for (int i = 0; i < n; i += 2) {
            int targetPartner = row[i] ^ 1;
            int personNextToMe = row[i+1];

            // if the people on the right hand side is not my partner
            if (personNextToMe != targetPartner) {
                ans++;
                // since the people on the right hand side is not my partner (stranger)
                // so we swap the personNextToMe and targetPartner position and the value in the row
                pos[personNextToMe] = pos[targetPartner];
                // pos[targetPartner] = pos[personNextToMe]; // actually we dont have to do this since we wont deal with targetPartner anymore after swap

                // swap the value in the row
                swap(personNextToMe, row[pos[targetPartner]]);
            }
        }
        return ans;
    }
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
    // partner[i] means the partner of i, it will be i+1 if i is even and i-1 if i is odd
    // and partner[pos[partner[row[i]]]] means the person sit at index i with value row[i] has partner partner[row[i]], 
    // whoes position is at pos[partner[row[i]]], and the partner of this position is partner[pos[partner[row[i]]]]
    // and we want i == partner[pos[partner[row[i]]]]
    // int minSwapsCouples(vector<int>& row) {
    //     int ans = 0;
    //     int n = row.size();

    //     vector<int> partner(n);
    //     vector<int> pos(n);
    //     // row:     [3,2,0,1]
    //     // pos:     [2,3,0,1] pos[i] means index of the person with value i in row array
    //     // partner: [1,0,3,2] partner[i] means the partner of i, it will be i+1 if i is even and i-1 if i is odd
    //     for (int i = 0; i < n; i++) {
    //         partner[i] = i^1;
    //         pos[row[i]] = i;
    //     }

    //     for (int i = 0; i < n; i++) {
    //         for (int j = partner[pos[partner[row[i]]]]; i != j; j = partner[pos[partner[row[i]]]]) {
    //             swap(row[i], row[j]);
    //             swap(pos[row[i]], pos[row[j]]);
    //             ans++;
    //         }
    //     }
    //     return ans;
    // }
};