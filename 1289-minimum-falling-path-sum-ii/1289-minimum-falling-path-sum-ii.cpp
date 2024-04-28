class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>>t(n,vector<int>(n,INT_MAX));
        
        int nextMinCol1=-1;
        int nextMinCol2=-1;
        
        for(int col=0;col<n;col++){
            t[n-1][col]=grid[n-1][col];
            
            if(nextMinCol1==-1||t[n-1][col]<=t[n-1][nextMinCol1]){
                nextMinCol2= nextMinCol1;
                nextMinCol1=col;
            }else if(nextMinCol2==-1||t[n-1][col]<=t[n-1][nextMinCol2]){
                nextMinCol2=col;
            }
        }
        for(int row=n-2;row>=0;row--){
            int minCol1=-1;
            int minCol2=-1;
            for(int col=0;col<n;col++){
                
           
               if(col != nextMinCol1){
                   t[row][col]=grid[row][col]+t[row+1][nextMinCol1];
               }else{
                   t[row][col]=grid[row][col]+t[row+1][nextMinCol2];
               }
                if(minCol1==-1||t[row][col]<=t[row][minCol1]){
                    minCol2=minCol1;
                    minCol1=col;
                }else if(minCol2==-1||t[row][col]<=t[row][minCol2]){
                    minCol2=col;
                }
            }
            nextMinCol1=minCol1;
            nextMinCol2=minCol2;
        }
        
        return t[0][nextMinCol1];
        
    }
};