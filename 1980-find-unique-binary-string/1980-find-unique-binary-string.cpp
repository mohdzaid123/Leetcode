class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int>st;
        
        for(string &num:nums){
//             convert binary ot string
            st.insert(stoi(num,0,2));
        }
        
        int n=nums.size();
        
        string result="";
        
        for(int number=0;number<=n;number++){
            if(st.find(number)==st.end()){
                result=bitset<16>(number).to_string();
                return result.substr(16-n,n);
            }
        }
        return "";
    }
};