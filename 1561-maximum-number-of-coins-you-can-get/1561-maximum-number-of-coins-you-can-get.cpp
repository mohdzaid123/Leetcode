class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        
        sort(begin(piles),end(piles));
        
        int result=0;
        
      
      
        
      for(int M=n/3;M<n;M+=2){
          result+=piles[M];
          
      }
        return result;
    }
};