class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string>bankset(bank.begin(),bank.end()); //quick access
        
        unordered_set<string>visited;
        queue<string>que;
        que.push(startGene);
        visited.insert(startGene);
        
        int level=0;
        
        while(!que.empty()){
            int n=que.size();
            while(n--){
                string curr=que.front();
                que.pop();
                
                if(curr==endGene){
                    return level;
                }
                
                for(char ch:"ACGT"){
                    for(int i=0;i<curr.length();i++){
                        string neigbour=curr;
                        neigbour[i]=ch;
                        
                        if(visited.find(neigbour)==visited.end()&& bankset.find(neigbour)!=bankset.end()){
                            visited.insert(neigbour);
                            que.push(neigbour);
                        }
                    }
                }
            }
            level++;
        }
        return -1;
         
        
    }
};