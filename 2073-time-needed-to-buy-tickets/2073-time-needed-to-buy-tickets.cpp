class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>>q;
        for(int a=0;a<tickets.size();a++){
            q.push({tickets[a],a});
        }
//         time taken
        int time_taken=0;
        while(q.empty()==false){
            time_taken++;
            pair<int,int> x=q.front();
            if(x.first-1<=0 && x.second==k)return time_taken;
                q.pop();
                if(x.first-1>0)
                q.push({x.first-1,x.second});
                
        }
//         return -1 if no time needed to buy ticket
        return -1;
    }
};