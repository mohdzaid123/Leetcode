class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        int n=heights.size();
        int maxdiff; 
        priority_queue<int,vector<int>> pq;
        int ans=0;

    int i;
        for(i=0;i<n-1;i++)
        {
            // differnce of two consecutive  consecutives
            maxdiff=heights[i+1]-heights[i];
        
            if(maxdiff>0)
            {
                // we ll use all bricks first 
                  bricks-=maxdiff;
                  // push into our queue 
                  pq.push(maxdiff);
                  if(bricks<0)
                  {
                      // if we both ladders and brick are none return index
                      if(ladders<=0)
                      return i;
                      // else  we push top most in queue and add to queue queue
                      int max_bricks=pq.top();
                      bricks+=max_bricks;
                      ladders--;
                      pq.pop();
                  }
           
            }
        }
            return i;

        
    }
};