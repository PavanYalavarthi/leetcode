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
    HashMap <Integer, Integer> hm = new HashMap<>();
    int ans = 0;
    public int amountOfTime(TreeNode root, int start) {
        dfs1(root);
        dfs2(root, start, 0);
        return ans;
    }
    int dfs1(TreeNode root){
        if(root == null) return 0;
        int val = Math.max(dfs1(root.left),dfs1(root.right));
        hm.put(root.val, val);
        return val + 1;
    }
    void dfs2(TreeNode  root, int target, int parVal) {
        if(root == null) return;
        if(root.val == target){
            ans = Math.max(parVal, hm.get(root.val));
            return;
        }
        if(root.left != null) {
            int right = 0;
            if(root.right != null) right = hm.get(root.right.val) + 2;
            dfs2(root.left, target, Math.max(parVal + 1, right));
        }
        if(root.right != null) {
            int left = 0;
            if(root.left != null) left = hm.get(root.left.val) + 2;
            dfs2(root.right, target, Math.max(parVal + 1, left));
        }
    }

    
}