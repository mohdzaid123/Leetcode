class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n=words.size();
        int count[26]={0};
        
        for(string &word:words){
            for(char &ch:word ){
                count[ch-'a']++;
            }
        }
        
        // for(auto &freq:count){
        //     // int freq=it.second;
        //     if(freq%n!=0){
        //         return false;
        //     }
        // }
        
        auto lamda=[&](int freq){
            return freq%n==0;
        };
        
        return all_of(begin(count),end(count),lamda);
        // return true;
        
    }
};