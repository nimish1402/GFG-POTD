

class Solution {
  
  public:
    // Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) {
        
        if(grid.empty() || grid[0].empty()) return 0;
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        
        int delrow[] ={-1, 0, +1, 0};
        int delcol[] = {0, +1, 0, -1};
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 'X' && !visited[i][j]){
                    count++;
                    queue<pair<int,int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    
                    while(!q.empty()){
                        int row = q.front().first;
                        int col = q.front().second;
                        q.pop();
                        
                        for(int i =0; i < 4; i++){
                            int nrow = row + delrow[i];
                            int ncol = col + delcol[i];
                            
                            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m &&
                                grid[nrow][ncol] == 'X' && !visited[nrow][ncol]){
                                    visited[nrow][ncol] = true;
                                    q.push({nrow, ncol});
                            }
                        }
                    }
                }
            }
        }
        return count;
        
    }
    
    
};