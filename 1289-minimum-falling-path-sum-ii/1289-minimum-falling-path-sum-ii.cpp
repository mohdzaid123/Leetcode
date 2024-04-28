class Solution {
public:
    int n;
    int t[201][201];
    int solve(int col,int row,vector<vector<int>>& grid){
        if(row==n-1){
            return grid[row][col];
        }
        
        if(t[row][col]!=-1){
            return t[row][col]; 
        }
        int ans=INT_MAX;
        for(int nextCol=0;nextCol<n;nextCol++){
            if(nextCol!=col){
                ans=min(ans,solve(nextCol,row+1,grid));
            }
        }
        return t[row][col] =ans+grid[row][col];
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n=grid.size();
        memset(t,-1,sizeof(t));
        
        int result=INT_MAX;
        for(int col=0;col<n;col++){
            result=min(result,solve(col,0,grid));
        }
        return result;
    }
};