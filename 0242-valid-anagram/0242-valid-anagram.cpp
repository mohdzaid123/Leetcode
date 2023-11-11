class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> mps;
        unordered_map<char,int> mpt;
        for(int i=0;i<s.length();i++){
                mps[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
                mpt[t[i]]++;
        }
        if(mps==mpt){
            return true;
        }
        return false;
    }
};