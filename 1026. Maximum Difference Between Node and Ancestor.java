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
    int res = 0;
    public int maxAncestorDiff(TreeNode root) {
        if(root == null) return 0;
        int min = root.val, max = root.val;
        diff(root,min,max);
        return res;
    }
    public void diff(TreeNode root, int min, int max){
        if(root == null) return;
        res = Math.max(res, Math.max(Math.abs(min - root.val), Math.abs(max - root.val)));
		min = Math.min(min, root.val);
		max = Math.max(max, root.val);
		diff(root.left, min, max);
		diff(root.right, min, max);
    }
}