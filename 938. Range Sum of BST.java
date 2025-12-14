/*
Problem credits: https://leetcode.com/problems/range-sum-of-bst/

Given the root node of a binary search tree and two integers low and high, return the sum of values of all nodes with a value in the inclusive range [low, high].

Solution:
    Use condition to add root value and navigate to left and right
*/
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int sum = 0;
    public void result(TreeNode root, int low, int high ) {

        if(root != null){
            if(root.val >= low && root.val <= high) sum += root.val;
            result(root.left, low, high);
            result(root.right, low, high);
        }
    }
    public int rangeSumBST(TreeNode root, int low, int high) {
        result(root, low, high);
        return sum;
    }
}