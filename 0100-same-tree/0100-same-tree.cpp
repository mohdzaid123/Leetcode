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

void inorder(TreeNode* root,vector<int>&v){
if(root!=NULL){
    inorder(root->left,v);
    v.push_back(root->val);
    inorder(root->right,v);
}else{
    v.push_back(10000);
}
}

void preorder(TreeNode* root,vector<int>&v){
if(root!=NULL){
    v.push_back(root->val);
    preorder(root->left,v);
    preorder(root->right,v);
}else{
    v.push_back(10000);
}
}



bool isSameTree(TreeNode* p, TreeNode* q) {

    vector<int> inp,inq,prep,preq;
      inorder(p,inp);
      inorder(q,inq);
      preorder(p,prep);
      preorder(q,preq);

      if(inp==inq && prep==preq){
          return true;
      }  else{
          return false;
      }
}
};