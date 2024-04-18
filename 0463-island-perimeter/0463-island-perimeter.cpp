class Solution {
public:
    int m;
    int n;

    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    int bfs(vector<vector<int>>& grid, int i, int j) {
        int perim = 0;
        
        queue<pair<int, int>> que;
        que.push({i, j});
        grid[i][j] = -1;
        
        while(!que.empty()) {
            
            auto it = que.front();
            que.pop();
            
            //it.first = i
            //it.second = j
            
            for(auto &dir : directions) {
                int i_ = it.first + dir[0];
                int j_ = it.second + dir[1];
                
                if(i_ < 0 || i_ >= m || j_ < 0 || j_ >= n || grid[i_][j_] == 0)
                    perim++;
                else if(grid[i_][j_] == -1) {
                    continue;
                } else {
                    que.push({i_, j_});
                    grid[i_][j_] = -1;
                }
            }
            
        }
        
        return perim;
    }
    
    int islandPerimeter(vector<vector<int>>& grid) {
        m    = grid.size();
        n    = grid[0].size();
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(grid[i][j] == 1) {
                    return bfs(grid, i, j);
                }
                
            }
        }
        
        return -1;
    }
};