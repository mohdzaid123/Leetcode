class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // size of array
        int n = nums.size();
// sort array
       sort(nums.begin(),nums.end());
// return product of two numbers
       return (nums[n - 1] - 1) * (nums[n - 2] - 1);
    }
};
