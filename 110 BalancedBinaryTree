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
 * 
 * Time complexity : O(n)
 * Space complexity : O(h)
 * Recursively checking for left and right for balanced, and validating the height difference is less than 2. 
 * Parallelly passing the current node height to caller 
 */
class Solution {
public:
    bool isBalanced(TreeNode* root) {
        int height = 0;
        return isBalancedHelper(root, height);
    }

    bool isBalancedHelper(TreeNode* root, int &height) {
        if (root == NULL) {
            height = 0;
            return true;
        }
        int lHeight, rHeight;
        if(isBalancedHelper(root->left, lHeight) && isBalancedHelper(root->right, rHeight) && abs(lHeight - rHeight) <= 1) {
            height = 1 + max(lHeight, rHeight); 
            return true;
        }
        return false;
    }
};