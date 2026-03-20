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
    // vector<int> lastVal = {};

    // bool dfs(TreeNode* root, int level) {
    //     if (!root) return true;
    //     if (root->val % 2 == level % 2) return false;
    //     if (lastVal.size() <= level) {
    //         lastVal.push_back(root->val);
    //     } else {
    //         if (level % 2 == 0 && root->val <= lastVal[level]) return false;
    //         if (level % 2 == 1 && root->val >= lastVal[level]) return false;
    //         lastVal[level] = root->val;
    //     }

    //     return dfs(root->left, level + 1) && dfs(root->right, level + 1);
    // }
    // bool bfs(TreeNode* root) {
    //     if (!root) return true;
    //     queue<TreeNode*> q;
    //     bool isOddLayer = true;
    //     q.push(root);
    //     while (q.size() != 0) {
    //         int size = q.size();
    //         int prev = (isOddLayer)?INT_MIN:INT_MAX;
    //         for (int i=0;i<size;i++){
    //             TreeNode* node = q.front();
    //             q.pop();
    //             int val = node->val;
    //             if (isOddLayer) {
    //                 if (val % 2 == 0) return false;
    //                 if (val <= prev) return false;
    //             } else {
    //                 if (val % 2 == 1) return false;
    //                 if (val >= prev) return false;
    //             }
    //             prev = val;
    //             if (node->left != nullptr) q.push(node->left);
    //             if (node->right != nullptr) q.push(node->right);
    //         }
    //         isOddLayer = !isOddLayer;
    //     }
    //     return true;
    // }

    bool isEvenOddTree(TreeNode* root) {
        if (root == nullptr) {
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            int prev_val = (level % 2 == 0) ? INT_MIN : INT_MAX;
            for (int n = q.size(); n--; ) {
                TreeNode* node = q.front();
                q.pop();

                // Check parity
                if (node->val % 2 == level % 2) {
                    return false;
                }
                
                // Check strict order
                if (level % 2) {
                    if (node->val >= prev_val) {
                        return false;
                    }
                }
                else {
                    if (node->val <= prev_val) {
                        return false;
                    }
                }
                
                prev_val = node->val;

                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            level++;
        }

        return true;
    }
};