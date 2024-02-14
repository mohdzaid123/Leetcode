class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);//Store answer Inside this
        int pos = 0 , neg = 0; //This is a pointer one for negative value and Another for Positive value
        //This is a pointer one for negative value and Another for Positive value
        for(int i = 0 ; i < n ; i++){
            if(i & 1){
                while(neg < n) //For Negative value For Negative value 
                {
                    if(nums[neg] < 0)
                        break;
                    neg++;
                }
                ans[i] = nums[neg];
                neg++;
            }
            else{
                while(pos < n)//For Positive Value
                {
                    if(nums[pos] > 0)
                        break;
                    pos++;
                }
                ans[i] = nums[pos];
//                 position ++
                pos++;
            }
        }
    return ans;
    }
};