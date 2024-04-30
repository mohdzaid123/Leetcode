class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int final_xor=0;
        for(int i=0;i<nums.size();i++){
            final_xor=final_xor^nums[i];  // final_xor will be xor of all the ele of nums
        }
        int count=0;
        while(k ||final_xor){
            if(k%2 != final_xor %2){
                count++;
            }
            k/=2;
            final_xor/=2;
        }    
     
    return count;
    }
};