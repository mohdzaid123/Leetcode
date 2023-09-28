class Solution {
public:

    static bool comparator(int &a,int &b){
        return a%2<b%2;
    }
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(begin(nums),end(nums),comparator);
        return nums;

    }
};