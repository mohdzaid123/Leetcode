class Solution {
public:
    string customSortString(string order, string s) {
        string ans;
        //step 1
        map<char,int> mpp;
        for(auto it: s)
            mpp[it]++;
        //step 2 
        for(int i=0;i<order.length()-1;i++){
          if(mpp.find(order[i])!=mpp.end())
          {
              int count=mpp[order[i]];
              while(count>0){
                  ans.push_back(order[i]);
                  count--;
                  }
          }
            mpp.erase(order[i]);
        }
        //step 3
        for(auto it: mpp){
          int count=it.second;
            while(count>0){
                ans.push_back(it.first);
                count--;}
        }
        return ans;
    }
};