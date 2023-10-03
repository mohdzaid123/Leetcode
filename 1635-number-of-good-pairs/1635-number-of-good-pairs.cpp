class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n=nums.size();

        int result=0;

        for(int i=0;i<n-1;i++){
            int num=nums[i];
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    result++;
                }
            }
        }
        return result;
    }
};