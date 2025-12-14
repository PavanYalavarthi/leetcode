/*
Problem credits: https://leetcode.com/problems/house-robber-iii/

The thief has found himself a new place for his thievery again. There is only one entrance to this area, called root.

Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that all houses in this place form a binary tree. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Given the root of the binary tree, return the maximum amount of money the thief can rob without alerting the police.


Solution: Use dfs, which returns pair<when this node is picked, when this node is not picked>
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
 */
class Solution {
public:
    int rob(TreeNode* root) {
        pair<int,int> result = dfs(root);
        return max(result.first, result.second);
    }

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        pair<int,int> left = dfs(root->left);
        pair<int,int> right = dfs(root->right);
        return {root->val + left.second + right.second, max(left.first, left.second) + max(right.first, right.second) };
    }
};