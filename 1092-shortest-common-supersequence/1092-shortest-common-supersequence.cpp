class Solution {
public:
//     int lcs(string &str1,string &str2,int m,int n, vector<vector<int>>& memo){
//         if(m==0&&n==0){
//             return 0;
//         }
        
//         if (memo[m][n] != -1) {
//             return memo[m][n];
//         }
//         if(str1[m-1]==str2[n-1]){
//             return memo[m][n]= 1+lcs(str1,str2,m-1,n-1,memo); 
//         }
        
        
        
//         return memo[m][n]= max(lcs(str1,str2,m-1,n,memo),lcs(str1,str2,m,n-1,memo)); 
        
//     }
    string shortestCommonSupersequence(string s1, string s2) {
        int m=s1.length();
        int n=s2.length();
        vector<vector<int>>t(m+1,vector<int>(n+1));
        // first row ans first column will have 0 value
        for(int row=0;row<m+1;row++){
            t[row][0]=0;
            
            
        }
        for(int col=0;col<n+1;col++){
            t[0][col]=0;
        }
        
        for(int i=1;i<m+1;i++){
            for(int j=1;j<n+1;j++){
                if(s1[i-1]==s2[j-1]){
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    t[i][j]=max(t[i-1][j],t[i][j-1]);
                }
            }
        }
        
        string lcs="";
        int i=m,j=n;
        
        while(i>0&&j>0){
            if(s1[i-1]==s2[j-1]){
                lcs.push_back(s1[i-1]);
                i--;
                j--;
            }else{
                if(t[i-1][j]>t[i][j-1]){
                    lcs.push_back(s1[i-1]);
                    i--;
                }else{
                     lcs.push_back(s2[j-1]);
                    j--;
                }
            }
        }
        while(i>0){
            lcs.push_back(s1[i-1]);
            i--;
        }
        while(j>0){
            lcs.push_back(s2[j-1]);
            j--;
        }
        reverse(begin(lcs),end(lcs));
        return lcs;
        
    }
};