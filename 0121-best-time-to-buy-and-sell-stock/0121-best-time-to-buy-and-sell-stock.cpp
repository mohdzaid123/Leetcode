class Solution {
public:
    int maxProfit(vector<int>& arr) {
      int mini=arr[0];
      int profit=0;
        for(int i=1;i<arr.size();i++){
            int diff=arr[i]-mini;
            profit=max(profit,diff);
            mini=min(arr[i],mini);
            }
        return profit;
    }
};