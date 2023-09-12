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
    int leftHeight(TreeNode* root) {
        if(!root)
            return 0;
        
        int lh = 0;
        TreeNode* temp = root;
        while(temp) {
            temp = temp->left;
            lh++;
        }
        return lh;
    }
    int rightHeight(TreeNode* root) {
        if(!root)
            return 0;
        
        int rh = 0;
        TreeNode* temp = root;
        while(temp) {
            temp = temp->right;
            rh++;
        }
        return rh;
    }
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        int lh = leftHeight(root);
        int rh = rightHeight(root);
        if(lh == rh) {
            return pow(2, lh) - 1;
        }
        
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};