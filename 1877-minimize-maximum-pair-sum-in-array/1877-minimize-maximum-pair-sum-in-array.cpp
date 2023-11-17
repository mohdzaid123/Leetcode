class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int i=0;
        int j=nums.size()-1;
       int result=0;
        
        while(i<j){
            int sum=nums[i]+nums[j];
            
            result=max(result,sum);
            i++;
            j--;
        }
        return result;
    }
};