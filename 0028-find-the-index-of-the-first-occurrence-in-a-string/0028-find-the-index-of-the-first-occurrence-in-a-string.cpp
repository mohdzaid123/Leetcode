class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        for(int i=0;i<=n-m;i++){
            int first=i ,second=0;
            while(second<m){
                if(haystack[first]!=needle[second]){
                    break;
                }else{
                     first++;
                second++;
                }
                if(m==second){
                    return first-second;
                }
               
            }
          
        }
          return -1;
        }
};