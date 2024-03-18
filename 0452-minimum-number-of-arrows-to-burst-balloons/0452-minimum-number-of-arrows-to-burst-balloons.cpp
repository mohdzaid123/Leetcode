class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        
        sort(begin(points),end(points));
        
        vector<int> prev=points[0];
        int count=1;
        for(int i=1;i<n;i++){
            int currStartPonit=points[i][0];
            int currEndPoints=points[i][1];
            
            int prevStartPoint=prev[0];
            int prevEndPoint=prev[1];
            
            if(currStartPonit>prevEndPoint){
                count++;
                prev=points[i];
                
            }else{
//                 100% overlap
//                 overlap region
                prev[0]=max(prevStartPoint,currStartPonit);
                prev[1]=min(currEndPoints,prevEndPoint);
            }
        }
        return count;
        
    }
};