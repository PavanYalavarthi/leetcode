/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 *
 * Time complexity : O(h)
 * Space complexity : O(1)
 * Based on value, we move to left if high is less than root, move to right, if root is less than low else LCA is root itself
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int low = min(p->val,q->val), high = max(p->val,q->val);
        while (root != nullptr) {
            if (high < root->val) root = root->left;
            else if (low > root->val) root = root->right;
            else break;
        }
        return root;
    }
};