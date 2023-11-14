class Solution {
public:
    bool checkBipartiteDFS(vector<vector<int>>& graph,int curr,vector<int> &color,int currColor){
        color[curr]=currColor;
        
        for(int &v:graph[curr]){
            if(color[v]==color[curr]){
                return false;
            }
            if(color[v]==-1){
              int colorOfV=1-currColor;
                if(checkBipartiteDFS(graph,v,color,colorOfV)==false){
                    return false;
                }
            }
            
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
         int n=graph.size();
        
        vector<int> color(n,-1);
        for(int i=0;i<n;i++){
            if(color[i]==-1){
               if(checkBipartiteDFS(graph,i,color,1)==false){
                   return false;
               } 
                
            }
           
        }
        return true;
    }
};