class Solution {
public:
    vector<vector<int>> ans;
    void solve(int i,vector<int>& nums,int n,vector<int> &temp){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        solve(i+1,nums,n,temp);
        temp.pop_back();
        solve(i+1,nums,n,temp);
        
        
        
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int> temp;
         solve(0,nums,n,temp);
        set<vector<int>> uniqueSubsets(ans.begin(), ans.end());
        std::vector<std::vector<int>> result(uniqueSubsets.begin(), uniqueSubsets.end());

        return result;
    }
};