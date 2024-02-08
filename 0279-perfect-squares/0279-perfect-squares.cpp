class Solution {
public:
    int minCoinsToGetS(vector<int>& coins, int n, int S, vector<vector<int>>& t) {
        if(t[n][S] != -1)
            return t[n][S];
        
        if(n == 0)
            return INT_MAX-1;
        if(S == 0)
            return 0;
        if(n == 1) {
            if(S % coins[0] == 0)
                return t[n][S] = S/coins[0];
            else
                return t[n][S] = INT_MAX-1;
        }
        
        if(coins[n-1] <= S) {
            return t[n][S] = min(1 + minCoinsToGetS(coins, n, S-coins[n-1], t), minCoinsToGetS(coins, n-1, S, t));
        } else
            return t[n][S] = minCoinsToGetS(coins, n-1, S, t);
    }
    int numSquares(int S) {
        vector<int> coins;
        for(int i = 1; i*i<=S; i++) {
            coins.push_back(i*i);
        }
        int n = coins.size();
        
        vector<vector<int>> t(n+1, vector<int>(S+1, -1));
        return minCoinsToGetS(coins, n, S, t);
    }
};