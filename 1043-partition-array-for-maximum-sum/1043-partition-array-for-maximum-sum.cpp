class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int>t(n+1,0);
        
        for(int size=1;size<=n;size++){
            int currmax=-1;
            for(int j=1;j<=k &&size-j>=0;j++){
                currmax=max(currmax,arr[size-j]);
                
                t[size]=max(t[size],(j*currmax)+t[size-j]);
            }
        }
        
        return t[n];
    }
};