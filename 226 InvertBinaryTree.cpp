/*
Problem credits: https://leetcode.com/problems/invert-binary-tree/

Given the root of a binary tree, invert the tree, and return its root.

Solution: Self explanatory
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
 * Space complexity : O(1)
 * Simple DFS, and swapping the left and right pointers
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root != nullptr) {
            TreeNode * tmp = root->left;
            root->left = invertTree(root->right);
            root->right = invertTree(tmp);
        }
        return root;
    }
};