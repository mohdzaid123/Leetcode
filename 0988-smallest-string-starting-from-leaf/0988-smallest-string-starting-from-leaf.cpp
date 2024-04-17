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
    string smallestFromLeaf(TreeNode* root) {
        queue<pair<TreeNode*, string>>que;
        
        que.push({root,string(1,char(root->val+'a'))});
        string result="";
        while(!que.empty()){
            auto[node,curr]=que.front();
            
            que.pop();
            
            if(!node->left&&!node->right){
                if(result==""||result>curr){
                    result=curr;
                }
            }
            if(node->left){
                que.push({node->left,char(node->left->val+'a')+curr});
            }
            
             if(node->right){
                que.push({node->right,char(node->right->val+'a')+curr});
            }
        }
        return result;
    }
};