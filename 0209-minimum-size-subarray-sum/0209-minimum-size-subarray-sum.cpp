class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int j=0,i=0;

        int minL=INT_MAX;

        int sum=0;

        while(j<n){
            sum+=nums[j];

            while(sum>=target){
                minL=min(minL,j-i+1);

                sum -=nums[i];
                // right shift of i
                i++;
            }
            j++;
        }
        return minL==INT_MAX?0:minL;
    }
};