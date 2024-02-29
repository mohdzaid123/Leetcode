class Solution {
public:
    bool isEvenOddTree(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        queue<TreeNode*> q;
        q.push(root);

        bool flag = true;

        while(!q.empty()){
            int size = q.size();
            vector<int> temp;

            
            for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();

                if(node->left){
                    q.push(node->left);
                }

                if(node->right){
                    q.push(node->right);
                }

                temp.push_back(node->val);
            }

            for(int i = 0;i<temp.size();i++){
                cout << temp[i];
            }

            cout << endl;

            if(flag == true){
                int n = temp.size();
                if(n == 1){
                    if(temp[0]%2 == 0) return false;
                    flag = false;
                    continue;
                }
                //hello
                if(temp[n-1]%2 == 0) return false;
                for(int i = 0;i<n-1;i++){
                    if(temp[i]%2 == 0){
                        return false;
                    }
                    if(temp[i] >= temp[i+1]){
                        return false;
                    }
                }
                flag = false;
            }else{
                int n = temp.size();
                if(n == 1){
                    if(temp[0]%2 == 1) return false;
                    flag = true;
                    continue;
                }
                if(temp[n-1]%2 == 1) return false;
                for(int i = 0;i<n-1;i++){
                    if(temp[i]%2 == 1){
                        return false;
                    }
                    if(temp[i] <= temp[i+1]){
                        return false;
                    }
                }
                flag = true;
            }
        }

        return true;
    }
};