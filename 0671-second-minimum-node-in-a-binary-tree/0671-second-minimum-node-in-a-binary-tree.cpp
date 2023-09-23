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
    int findSecondMinimumValue(TreeNode* root) {
        if(root==NULL){
            return -1;
        }
        if(root->left==NULL&&root->right==NULL){
            return -1;
        }

        int leftSecondMin=root->left->val;
        int rightSecondMin=root->right->val;

        // condiotional recursive faith
        if(root->val==root->left->val){
            leftSecondMin=findSecondMinimumValue(root->left);
        }

        if(root->val==root->right->val){
            rightSecondMin=findSecondMinimumValue(root->right);
        }

        if(leftSecondMin !=-1 && rightSecondMin !=-1){
                return min(leftSecondMin,rightSecondMin);
        }else if(leftSecondMin==-1){
            return  rightSecondMin;
        }
        else{
            return leftSecondMin;
        }
    }
};