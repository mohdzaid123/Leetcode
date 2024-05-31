class Solution {
public:
    int m,n;
    int t[501][501];
    int solve(string &s1,string &s2,int m,int n){
        // if(i==m){
        //     return n-j; //insert in s1
        // }else
        // if(j==n){
        //     return m-i;  //delete in s2
        // }
        if(m==0||n==0){
            return m+n;
        }
        
        if(t[m][n]!=-1){
            return t[m][n];
        }
        
        if(s1[m-1]==s2[n-1]){
            return t[m][n]= solve(s1,s2,m-1,n-1);
        }else{
            int insertC=1+solve(s1,s2,m,n-1);
            int deleteC=1+solve(s1,s2,m-1,n);
            int replaceC=1+solve(s1,s2,m-1,n-1);
            
            return t[m][n]= min({insertC,deleteC,replaceC});
        }
        return -1;
        
        
    }
    int minDistance(string word1, string word2) {
         m=word1.length();
         n=word2.length();
        memset(t,-1,sizeof(t));
        return solve(word1,word2,m,n);
    }
};