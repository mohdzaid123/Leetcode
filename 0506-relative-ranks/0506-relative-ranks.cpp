class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n=score.size();
        vector<string>result(n);
        
        priority_queue<pair<int,int>>pq;
        
        for(int i=0;i<n;i++){
            pq.push({score[i],i});
        }
        
        int rank=1;
        
        while(!pq.empty()){
            int idx=pq.top().second;
            
            pq.pop();
            
            if(rank==1){
                result[idx]="Gold Medal";
            }else if(rank==2){
                result[idx]="Silver Medal";
            }else if(rank==3){
                result[idx]="Bronze Medal";
            }else{
                result[idx]=to_string(rank);
            }
            rank++;
        }
        return result;
    }
};