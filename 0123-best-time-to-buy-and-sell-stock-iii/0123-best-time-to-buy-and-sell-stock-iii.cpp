class Solution {
public:
    int f(int ind,int buy,int cap,vector<int>&prices,int n,vector<vector<vector<int>>>&dp){
        if(ind==n||cap==0){
            return 0;
        }
        if(dp[ind][buy][cap]!=-1){
            return dp[ind][buy][cap];
        }
        if(buy==1){
            return dp[ind][buy][cap]= max(-prices[ind]+f(ind+1,0,cap,prices,n,dp),0+f(ind+1,1,cap,prices,n,dp));
        }
        return dp[ind][buy][cap]= max(prices[ind]+f(ind+1,1,cap-1,prices,n,dp),0+f(ind+1,0,cap,prices,n,dp));
    }
    
    int solveTab(vector<int>& prices){
        int n=prices.size();
         // vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2,vector<int>(3,0)));
        vector<vector<int>>curr(2,vector<int>(3,0));
        vector<vector<int>>next(2,vector<int>(3,0));
        
        for(int index =n-1;index>=0;index--){
            for(int buy=0;buy<=1;buy++){
                for(int limit=1;limit<=2;limit++){
                    int profit=0;
                    
                    if(buy){
                        int buyKaro=-prices[index]+next[0][limit];
                        int skipKaro=0+next[1][limit];
                        profit=max(buyKaro,skipKaro);
                    }else{
                        int sellKaro=prices[index]+next[1][limit-1];
                        int skipKaro=0+next[0][limit];
                        profit=max(sellKaro,skipKaro);
                    }
                    curr[buy][limit]=profit;
                }
            }
            next=curr;
        }
        return next[1][2];
    }
    int maxProfit(vector<int>& prices) {
        
//          int n=prices.size();
//         vector<vector<vector<int>>>dp(n, vector<vector<int>>(2,vector<int>(3,-1)));
       
//         return f(0,1,2,prices,n,dp) ;
        return solveTab(prices);
    }
};