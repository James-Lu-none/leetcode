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
    bool treeToVec(TreeNode* root, int level, vector<vector<int>>& v) {
        if (root == nullptr) return true;

        if (v.size()<=level) {
            v.push_back({});
        }
        if (level % 2 == root->val % 2) return false;
        if (v[level].size() > 0) {
            if (level % 2 == 0 && v[level].back() >= root->val) return false;
            if (level % 2 == 1 && v[level].back() <= root->val) return false;
        }
        v[level].push_back(root->val);

        
        bool a = treeToVec(root->left, level+1, v);
        if (!a) return false;
        bool b = treeToVec(root->right, level+1, v);
        if (!b) return false;
        return true;
    }
    bool isEvenOddTree(TreeNode* root) {
        // vector<TreeNode*> v;
        vector<vector<int>> v;
        return treeToVec(root, 0, v);
    }
};