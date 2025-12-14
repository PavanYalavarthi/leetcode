/*
Problem credits: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus the sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search trees.


Solution:
    pick top 2 stones and push (x-y)
*/
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>q(stones.begin(), stones.end());
        while(q.size() > 1){
            int x = q.top();
            q.pop();
            int y = q.top();
            q.pop();
            q.push(x - y);
        }
        return q.empty() ? 0 : q.top();
    }
};