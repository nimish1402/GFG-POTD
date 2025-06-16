class Solution {
  
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        // convert 2D array to adj list 
        vector<vector<int>> adj(V);
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool> visited(V, false); //visited array
        
        for(int i = 0; i < V; ++i){
            if(!visited[i]){
                queue<pair<int,int>> q;
                q.push({i, -1});
                visited[i] = true;
                
                while(!q.empty()){
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    
                    for(int neighbour : adj[node]){
                    
                        if(!visited[neighbour]){
                            visited[neighbour] = true;
                            q.push({neighbour, node});
                        }
                        else if(neighbour != parent){
                            return true;
                        }
                    }
                    
                }
            }
        }
        return false;
    }
};