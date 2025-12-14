/*
Problem credits: https://leetcode.com/problems/binary-tree-inorder-traversal/

Given the root of a binary tree, return the inorder traversal of its nodes' values.

Solution: Inorder traversal (left, root, right)
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>v;
        if(!root) return v;
        stack<TreeNode*>s;
        while(!s.empty() || root != NULL){
            while(root){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            v.push_back(root->val);
            root = root->right; 
        }
        return v;
    }
};