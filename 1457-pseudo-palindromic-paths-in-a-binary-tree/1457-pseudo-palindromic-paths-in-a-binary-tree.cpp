
class Solution {
public:
    int result=0;
    void solve(TreeNode* root,vector<int> &count){
        if(root==NULL){
            return ;
        }
        count[root->val]++;
        
        if(root->left==NULL&&root->right==NULL)
        {
            int oddFreq=0;
            for(int i=1;i<=9;i++){
                if(count[i]%2!=0){
                   oddFreq++;
                }
            }
            
            if(oddFreq<=1){
                result+=1;
            }
            
           
        }
        
        solve(root->left,count);
        solve(root->right,count);
        
         count[root->val]--;
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> count(10,0);
        solve(root,count);
        return result;
        
    }
};