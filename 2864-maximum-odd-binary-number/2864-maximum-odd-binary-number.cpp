class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int n=s.length();
        
        string result=string(n,'0');
        
        int i=0;
        
        for(char &ch:s){
            if(ch=='1'){
                if(result[n-1]=='1'){   //LSB ='1' for it to be ODD number
                    result[i]='1';
                    i++;
                }else{
                    result[n-1]='1';
                }
            }
        }
        return result;
    }
};