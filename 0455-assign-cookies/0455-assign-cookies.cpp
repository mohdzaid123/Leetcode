class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(s),end(s));
        sort(begin(g),end(g));
        
        
        int m=g.size();
        int n=s.size();
        
        int i=0;
        int j=0;
        
        while(i<m&&j<n){
            if(g[i]<=s[j]){
                i++;
                
            }
            j++;
        }
        return i; 
    }
};