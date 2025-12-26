/*
problem credits: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/description/

You are given the root of a binary tree with unique values, and an integer start. At minute 0, an infection starts from the node with value start.

Each minute, a node becomes infected if:

The node is currently uninfected.
The node is adjacent to an infected node.
Return the number of minutes needed for the entire tree to be infected.

Solution:
    Do dfs and once start is in sub array, return true and max height from start to other part of the child
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
    int ans = 0;
public:
    pair<bool, int> dfs(TreeNode* root, int start) {
        if (root == nullptr) return {false, 0};
        pair<bool, int> left = dfs(root->left, start);
        pair<bool, int> right = dfs(root->right, start);

        if (root -> val == start) {
            ans = max(left.second, right.second);
            return {true, 0};
        }

        if (left.first) {
            ans = max(ans, left.second + right.second + 1);
            return {true, left.second+1};
        } else if (right.first) {
            ans = max(ans, right.second + left.second + 1);
            return {true, right.second+1};
        }
        return {false, max(left.second, right.second) + 1};
    }

    int amountOfTime(TreeNode* root, int start) {
        dfs(root, start);
        return ans;
    }
};