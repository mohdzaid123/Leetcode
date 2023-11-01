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
int currNum=0;
int currFreq=0;
int maxFreq=0;
vector<int> result;

void dfs(TreeNode* root){
    if(!root){
        return;
    }
    dfs(root->left);
    if(root->val==currNum){
        currFreq++;
    }else{
        currNum=root->val;
         currFreq=1;
    }

    if(currFreq>maxFreq){
        result={};
        maxFreq=currFreq;

    }
    if(currFreq==maxFreq){
        result.push_back(currNum);
    }

    dfs(root->right);
}

    vector<int> findMode(TreeNode* root) {
        dfs(root);

        return result;
    }
};