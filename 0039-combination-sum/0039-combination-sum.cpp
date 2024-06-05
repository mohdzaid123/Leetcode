class Solution {
public:
    vector<vector<int>>result;
     void solve(int i , vector<int>&ans,int target,vector<int>& candidates){
         
         if(target==0){
             result.push_back(ans);
                 return;
         }
         if (i >= candidates.size() || target < 0) {
            return;
        }
         ans.push_back(candidates[i]);
         solve(i,ans,target-candidates[i],candidates);
         ans.pop_back();
         solve(i+1,ans,target,candidates);     
     }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       
        vector<int>ans;
        
         solve(0,ans,target,candidates); 
        return result;
    }
};