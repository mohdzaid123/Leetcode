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
    int maxLevelSum(TreeNode* root) {
        int maxSum=INT_MIN;
        int resultLevel=0;
        queue<TreeNode*> que;
        que.push(root);

        int currentLevel=1;

        while(!que.empty()){
            int n=que.size();
            int sum=0;

            while(n--){
                TreeNode* temp=que.front();
                que.pop();

                sum+=temp->val;

                if(temp->left){
                    que.push(temp->left);
                }
                if(temp->right){
                    que.push(temp->right);
                }
            }
            if(sum>maxSum){
                maxSum=sum;
                resultLevel=currentLevel;
            }

            currentLevel++;
        }

        return resultLevel;
    }
};