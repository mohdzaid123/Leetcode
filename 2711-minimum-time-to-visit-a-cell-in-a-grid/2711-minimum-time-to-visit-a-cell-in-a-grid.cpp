// class Solution {
// public:
//     vector<vector<int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
//     #define P pair<int, pair<int, int>>

//     int minimumTime(vector<vector<int>>& grid) {
//         int m = grid.size();
//         int n = grid[0].size();

//         if (grid[0][1] > 1 && grid[1][0] > 1)
//             return -1;
        
//         vector<vector<bool>> visited(m, vector<bool>(n, false));
//         priority_queue<P, vector<P>, greater<P>> pq;
        
//         pq.push({grid[0][0], {0, 0}}); // Start at top-left corner
//         while (!pq.empty()) {
//             // Get the current time, row, and column
//             int time = pq.top().first;
//             int row  = pq.top().second.first;
//             int col  = pq.top().second.second;
//             pq.pop();
            
//             // Reached destination
//             if (row == m - 1 && col == n - 1)
//                 return time;
            
//             // Mark the current cell as visited
//             if (visited[row][col]) continue;
//             visited[row][col] = true;
            
//             // Explore the neighboring cells
//             for (auto dir: direction) {
//                 int r = row + dir[0];
//                 int c = col + dir[1];
//                 if (r < 0 || r >= m || c < 0 || c >= n || visited[r][c])
//                     continue;
                
//                 if (grid[r][c] <= time+1)
//                     pq.push({time+1, {r, c}});
//                 else if ((grid[r][c]-time)%2==0)
//                     pq.push({grid[r][c]+1, {r, c}});
//                 else
//                     pq.push({grid[r][c], {r, c}});
//             }
//         }
//         return -1;
//     }
// };


//Approach-3 (You can skip using visited array) - Credits to : @nikhil_squats <3
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        
        if(grid[0][1]>1 && grid[1][0]>1) return -1;
        int m=grid.size();
        int n=grid[0].size();

        vector<vector<int>> time(m,vector<int>(n,INT_MAX));
        time[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{0,0}});

        while(!pq.empty()){
            int curr_time=pq.top().first;
            int row=pq.top().second.first;
            int col=pq.top().second.second;
            pq.pop();

            if(row==m-1 && col==n-1) return curr_time;

            int dx[]={0,-1,0,1};
            int dy[]={-1,0,1,0};

            for(int i=0;i<4;i++){
                int nrow=dx[i]+row;
                int ncol=dy[i]+col;
                bool cond=(nrow>=0 && nrow<m && ncol>=0 && ncol<n);

                if(cond){
                    int diff=grid[nrow][ncol]-curr_time;
                    int new_time;
                    if(curr_time>=grid[nrow][ncol]){
                        new_time=curr_time+1;
                    }
                    else if(diff%2==1){
                        new_time=grid[nrow][ncol];
                    }
                    else{
                        new_time=grid[nrow][ncol]+1;
                    }
                    

                    if(time[nrow][ncol]>new_time){
                        time[nrow][ncol]=new_time;
                        pq.push({new_time,{nrow,ncol}});
                    }
                }
            }
        }
        
        return -1; //never reach
    }
};