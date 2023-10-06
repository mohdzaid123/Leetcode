class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(int num:nums){
            if(st.count(num)>0){
                return true;
            }
            st.insert(num);
        }

        return false;
    }

    
    
};