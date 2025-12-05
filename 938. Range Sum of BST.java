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