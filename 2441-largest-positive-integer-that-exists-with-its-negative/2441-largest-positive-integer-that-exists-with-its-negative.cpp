class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int arr[2001]={0};
        
        int result=-1;
        
        for(int &num:nums){
            if(arr[-num+1000]==1){
                result=max(result,abs(num));
            }
            arr[num+1000]=1;
        }
        return result;
        
    }
};