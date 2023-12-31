class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        // int len=s.length();
        int result=-1;
        int n=s.length();
        for(int i=0;i<n;i++){
            for(int j=1;j<n;j++){
                if(s[i]==s[j]){
                    result=max(result,j-i-1);
                }
            }
        }
        return result;
    }
};