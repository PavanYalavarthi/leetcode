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
private:
  void func(TreeNode* root, string & s){
    if(root){
      s.append(to_string(root->val));
      if(root->left || root->right){
        s.push_back('(');
        func(root->left,s);
        s.push_back(')');
        if(root -> right){
          s.push_back('(');
          func(root->right,s);
          s.push_back(')');
        }
      }
    }
  }
  
public:
    string tree2str(TreeNode* root) {
        string ans = "";
        func(root,ans);
        return ans;
    }
};