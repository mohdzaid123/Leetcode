class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // sort(begin(happiness),end(happiness),greater<int>());
        
//         long long result=0;
        
//         int count=0;
        
//         for(int i=0;i<k;i++){
//             result+=max(happiness[i]-count,0);
//             count++;
//         }
//         return result;
        
        long long result=0;
        
        int count=0;
        
        priority_queue<int>pq;
        
        for(int &hap:happiness){
            pq.push(hap);
        }
        
        for(int i=0;i<k;i++){
            int hap=pq.top();
            pq.pop();
            
            result += max(hap-count,0);
            
            count++;
        }
        return result;
    }
};