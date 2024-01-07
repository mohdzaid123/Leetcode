class Solution {
public:
//     int solve(vector<int>&cost,int n){
// //         base case
//         if(n==0){
//             return cost[0];
//         }
//         if(n==1){
//             return cost[1];
//         }
        
//         int ans=cost[n]+min(solve(cost,n-1),solve(cost,n-2));
//            return ans; 
//     }
    
    
    int solve(vector<int>&cost,int n,vector<int>&dp){
//         base case
        if(n==0){
            return cost[0];
        }
        if(n==1){
            return cost[1];
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        
        dp[n]=cost[n]+min(solve(cost,n-1,dp),solve(cost,n-2,dp));
           return dp[n]; 
    }
    
    int solve2(vector<int>&cost,int n){
//         base case
//         step 1 create dp array
        vector<int> dp(n+1);
        // base case analyse
        dp[0]=cost[0];
        dp[1]=cost[1];
        
//         step 3
        for(int i=2 ;i<n;i++){
            dp[i]=cost[i]+min(dp[i-1],dp[i-2]);
        }
        
       return min(dp[n-1],dp[n-2]);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        // int n=cost.size();
        // // can be simlified
        // int ans=min(solve(cost,n-1),solve(cost,n-2));
        // return ans;
        int n=cost.size();
        // step 1
        // vector<int>dp(n+1,-1);
        // int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return solve2(cost,n);
        
    }
};