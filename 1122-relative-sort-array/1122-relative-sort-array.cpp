class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
       vector<int> ans;
       map<int,int> mp;

       for(auto x:arr1){
           mp[x]++;

       } 
       for(auto temp:arr2){
           if(mp.find(temp)!=mp.end()){
               auto x=mp.find(temp);
               int count=x->second;
               vector<int> v(count,temp);  //short hand //22 333 count value 
               ans.insert(ans.end(),v.begin(),v.end());
               mp.erase(temp);
           }
       }

       for(auto x:mp){
           int ele=x.first;
           int count=x.second;
           vector<int> v(count,ele);
           ans.insert(ans.end(),v.begin(),v.end());
       }
       return ans;
    }
};