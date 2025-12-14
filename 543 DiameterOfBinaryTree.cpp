/*
problem credits: https://leetcode.com/problems/diameter-of-binary-tree/

Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.


Solution:
    DFS on tree and getting height back to root node. Updating ans when lHeight + rHeight is max
*/
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