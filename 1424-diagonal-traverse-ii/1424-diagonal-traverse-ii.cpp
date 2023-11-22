//Approach-1 (Using map)
//T.C : O(n) where n = all elements in grid
//S.C : O(n) We took map to store all elements
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int, vector<int>> mp;
        
        
        for(int row = nums.size()-1; row >= 0; row--) {
            for(int col = 0; col < nums[row].size(); col++) {
                
                mp[row+col].push_back(nums[row][col]);
                
            }
        }
        
        vector<int> result;
        int diagonal = 0;
        
        while(mp.find(diagonal) != mp.end()) {
            
            for(int &num : mp[diagonal]) {
                result.push_back(num);
            }
            diagonal++;
        }
        
        return result;
        
    }
};