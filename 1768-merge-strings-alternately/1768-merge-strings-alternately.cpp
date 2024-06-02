class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m=word1.length();
        int n=word2.length();
        int i=0,j=0;
        string mergeWord="";
        while(i<m&&j<n){
            if(mergeWord.length()%2==0){
                mergeWord.push_back(word1[i]);
                i++;
            }else{
                mergeWord.push_back(word2[j]);
                j++;
            }
           
        }
        
        while(i<m){
             mergeWord.push_back(word1[i]);
            i++;
        }
        while(j<n){
            mergeWord.push_back(word2[j]);
            j++;
        }
        return mergeWord;
    }
};