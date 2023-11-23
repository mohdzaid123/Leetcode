class Solution {
public:
    bool check(vector<int>& arr){
       
        int n=arr.size();
        int minE=INT_MAX;
        int maxE=INT_MIN;
        
        
        unordered_set<int>st;
        
        for(int &num:arr){
            minE=min(minE,num);
            maxE=max(maxE,num);
            st.insert(num);
        }
        
        if((maxE-minE)%(n-1)!=0){
            return false;
        }
        int d=(maxE-minE)/(n-1);
        
        int curr=minE;
        
        while(curr<maxE){
            if(st.find(curr)==st.end()){
                return false;
            }
            curr+=d;
        }
        
        return true;
        
        
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
     int m=l.size();
        
        vector<bool> result;
        
        for(int i=0;i<m;i++){
            int start=l[i];
            int end=r[i];
            
           
                
                vector<int>arr(begin(nums)+start,begin(nums)+end+1);
//             start to end
            bool isAP=check(arr);
            
            result.push_back(isAP);
            
        }
        return result;
    }
};