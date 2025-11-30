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
 * Time complexity : O(n)
 * Space complexity : O(h)
 * DFS on tree and getting height back to root node. Updating ans when lHeight + rHeight is max
 */
class Solution {
public:
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        helper(root, ans);
        return ans;
    }

    int helper(TreeNode* root, int & ans) {
        if(root == NULL) return 0;
        int lHeight = helper(root -> left, ans);
        int rHeight = helper(root -> right, ans);
        ans = max(ans, lHeight + rHeight);
        return 1 + max(lHeight, rHeight);
    }
};