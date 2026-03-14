/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void treeToVec(TreeNode* root, int level, vector<vector<int>>& v) {
        if (root == nullptr) return;

        if (v.size()<=level) {
            v.push_back({});
        }

        v[level].push_back(root->val);
        
        treeToVec(root->right, level+1, v);
        treeToVec(root->left, level+1, v);
        return;
    }
    bool isEvenOddTree(TreeNode* root) {
        // vector<TreeNode*> v;
        vector<vector<int>> v;
        treeToVec(root, 0, v);
        bool isEvenLayer = false;
        int layer = 0;

        for (vector vec: v){

            int prev;
            if (!isEvenLayer){
                prev = INT_MAX;
            } else {
                prev = INT_MIN;
            }
            for (int value: vec){
                printf("layer: %d, prev: %d, value: %d\n", layer, prev, value);
                if (value % 2 == 0 && !isEvenLayer){
                    printf("case1");
                    return false;
                }
                if (value % 2 == 1 && isEvenLayer){
                    printf("case2");
                    return false;
                }
                if (prev <= value && !isEvenLayer){
                    printf("case3");
                    return false;
                } 
                if (prev >= value && isEvenLayer){
                    printf("case4");
                    return false;
                }
                prev = value;
            }
            isEvenLayer = !isEvenLayer;
            layer++;
        }
        return true;
    }
};