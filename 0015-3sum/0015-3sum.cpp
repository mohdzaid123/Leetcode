class Solution {
public:
    vector<vector<int>>result;

    void twoSum(vector<int>&nums,int target,int i,int j){
        while(i<j){
            if(nums[i]+nums[j]>target){
                j--;
            }else
                if(nums[i]+nums[j]<target){
                    i++;
                }
            else{
                // we will remove duplicate from array nums
                while(i<j && nums[i]==nums[i+1]){
                        i++;
                }
                while(i<j && nums[j]==nums[j-1]){
                    j--;
                }

                result.push_back({-target,nums[i],nums[j]});
                i++;
                j--;
            }
        }
    }

    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();

        if(n<3){
            return {};
        }

        result.clear();

        sort(begin(nums),end(nums));
        // fixing n1
        for(int i=0;i<n;i++){
                if(i>0 && nums[i]==nums[i-1]){
                    continue;
                }
                int n1=nums[i];
                int target=-n1;

                twoSum(nums,target,i+1,n-1); //it will find n2 and n3
        }
        return result;
    }
};