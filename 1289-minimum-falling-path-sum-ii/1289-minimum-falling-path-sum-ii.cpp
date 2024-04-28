class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>t(n,vector<int>(n,INT_MAX));
        
        for(int col=0;col<n;col++){
            t[n-1][col]=grid[n-1][col];
        }
        for(int row=n-2;row>=0;row--){
            for(int col=0;col<n;col++){
                int ans=INT_MAX;
                for(int nextCol=0;nextCol<n;nextCol++){
                    if(nextCol!=col){
                        ans=min(ans,t[row+1][nextCol]);
                    }
                }
                t[row][col]=grid[row][col]+ans;
            }
        }
        int result=INT_MAX;
        for(int col=0;col<n;col++){
            result=min(result,t[0][col]);
        }
        return result;
        
    }
};