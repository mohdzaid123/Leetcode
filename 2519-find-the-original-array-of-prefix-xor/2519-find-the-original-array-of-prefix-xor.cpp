class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n= pref.size();

        for(int i=n-1;i>0;i--){
        //   arr.push_back(pref[i]^pref[i-1]);
        pref[i]=pref[i]^pref[i-1];
        }
        return pref;
    }
};