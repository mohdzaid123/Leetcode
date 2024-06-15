class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
     while(stones.size()>1){
         sort(begin(stones),end(stones));
         int a=stones.back(); stones.pop_back();
         int b=stones.back(); stones.pop_back();
         
         stones.push_back(abs(a-b));
     }   
        return stones[0];
    }
};