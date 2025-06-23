// User function Template for C++

class Solution {
  public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> src,
                     pair<int, int> destination) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        
        if(src.first == destination.first && src.second == destination.second){
            return 0;
        }
        
        dist[src.first][src.second] = 0;
        q.push({0, {src.first, src.second}});
        
        int delrow[] = {-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            
            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;
            
            for(int i = 0; i < 4; i++){
                
                int newrow = row + delrow[i];
                int newcol = col + delcol[i];
                
                if(newrow >= 0 && newrow < n && newcol >= 0 && newcol < m
                    && grid[newrow][newcol] == 1 && dis + 1 < dist[newrow][newcol]){
                        
                        dist[newrow][newcol] = dis + 1;
                        
                        if(newrow == destination.first && newcol == destination.second){
                            return dis + 1;
                        }
                        q.push({1+ dis, {newrow, newcol}});
                    }
            }    
            
        }
        return -1;
    }
};
 