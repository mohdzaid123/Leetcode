class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        
        int t[71][71][71]={0};
      //t row[c1][c2]=max cherries collected till now,c1 by robot  
        t[0][0][n-1]=(n==1)?grid[0][0]:grid[0][0]+grid[0][n-1];
        
        for(int row=1;row<m;row++){
            for(int c1=0;c1<=min(n-1,row);c1++){
                for(int c2=max(0,n-row-1);c2<n;c2++){
                    int prevRowMax=0;
                    for(int prevCol1=max(c1-1,0);prevCol1<=min(n-1,c1+1);prevCol1++){
                        for(int prevCol2=max(c2-1,0);prevCol2<=min(n-1,c2+1);prevCol2++){
                        prevRowMax=max(prevRowMax,t[row-1][prevCol1][prevCol2]);
                    }
                    }
                    if(c1==c2){
                        t[row][c1][c2]=prevRowMax+grid[row][c1];
                    }else{
                        t[row][c1][c2]=prevRowMax+grid[row][c1]+grid[row][c2];
                    }
                    
                }
            }
        }
        int result=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                result=max(result,t[m-1][i][j]);
            }
        }
        return result;
    }
};