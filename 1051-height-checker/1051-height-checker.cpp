class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int>result(heights);
        for(int i=0;i<heights.size()-1;i++){
           
            result[i]=heights[i];
        }
        
        sort(begin(result),end(result));
        int count=0;
        for(int idx=0;idx<=result.size()-1;idx++){
            if(result[idx]!=heights[idx]){
                 count++;
            }
           
        }
        return count;
        
    }
};