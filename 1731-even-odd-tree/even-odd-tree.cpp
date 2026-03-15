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
    vector<int> lastVal = {};

    bool dfs(TreeNode* root, int level) {
        if (!root) return true;
        if (root->val % 2 == level % 2) return false;
        if (lastVal.size() <= level) {
            lastVal.push_back(root->val);
        } else {
            if (level % 2 == 0 && root->val <= lastVal[level]) return false;
            if (level % 2 == 1 && root->val >= lastVal[level]) return false;
            lastVal[level] = root->val;
        }

        return dfs(root->left, level + 1) && dfs(root->right, level + 1);
    }

    bool isEvenOddTree(TreeNode* root) {
        return dfs(root, 0);
    }
};