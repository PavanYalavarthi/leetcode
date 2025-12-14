/*
problem credits: https://leetcode.com/problems/binary-tree-level-order-traversal/

Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

Solution: 
    basic DFS, with indexing at depth
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        helper(root, v, 0);
        return v;
    }

    void helper(TreeNode* root, vector<vector<int>>& v, int index) {
        if (root == NULL) return;
        if (v.size() ==  index) v.push_back({root->val});
        else v[index].push_back(root->val);
        helper(root->left, v, index + 1);
        helper(root->right, v, index + 1);   
    }
};