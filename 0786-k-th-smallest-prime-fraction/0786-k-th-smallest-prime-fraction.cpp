class Solution {
public:
    typedef vector<double> V; 
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        priority_queue<V,vector<V>,greater<V>>pq;
        
        for(int i=0;i<n;i++){
            pq.push({1.0*arr[i]/arr[n-1],(double)i,(double)n-1});
        }
        
        int smallest=1;//first smallest
        while(smallest<k){
            V vec=pq.top();
            pq.pop();
            
            int i=vec[1];
            int j=vec[2]-1;
            
            pq.push({1.0*arr[i]/arr[j],(double)i,(double)j});
            smallest++;
            
            
        }
        V vec=pq.top();
        int i=vec[1];
        int j=vec[2];
        
        return {arr[i],arr[j]};
        
        
    }
};