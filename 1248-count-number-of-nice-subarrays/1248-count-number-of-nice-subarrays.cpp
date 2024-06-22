class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int oddCount=0;
        int prevCount=0;
        int result=0;
        int n=nums.size();
        int i=0;
        int j=0;
        
        while(j<n){
            if(nums[j]%2!=0){
                oddCount++;
                prevCount=0;
            }
            while(oddCount==k){
                prevCount++;
                
                if(i<n && nums[i]%2==1){
                    oddCount--;
                }
                i++;
            }
            
            result+=prevCount;
            j++;
        }
        return result;
    }
};