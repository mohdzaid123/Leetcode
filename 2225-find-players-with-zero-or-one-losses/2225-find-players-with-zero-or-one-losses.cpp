class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int>lost_map;
            
    // for(auto &it:matches){
    //     int lose=
    // }
        for(int i=0;i<matches.size();i++){
            int loser=matches[i][1];
            lost_map[loser]++;
        }
        
        vector<int> notLost;
        vector<int> lostOnce;
        
        for(int i=0;i<matches.size();i++){
            int winner=matches[i][0];
            int loser=matches[i][1];
            
            
            if(lost_map.find(winner)==lost_map.end()){
                notLost.push_back(winner);
                lost_map[winner]=2;
            }
            
            if(lost_map[loser]==1){
                lostOnce.push_back(loser);
            }
        }
        
        sort(begin(lostOnce),end(lostOnce));
        sort(begin(notLost),end(notLost));
        
        
        
        return {notLost,lostOnce};
    }
};