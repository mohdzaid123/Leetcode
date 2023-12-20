class Solution {
public:
    void subSequence(vector<int>& nums, int index, int n, vector<vector<int>> &ans, vector<int> temp)
{
    if (index == n)
    {
        ans.push_back(temp);
        return;
    }

    // not Include
    subSequence(nums, index + 1, n, ans, temp);
    // Include
    temp.push_back(nums[index]);
    subSequence(nums, index + 1, n, ans, temp);
}
    
    
    
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> temp;
    subSequence(nums, 0, nums.size(), ans, temp);
        return ans;
    }
};