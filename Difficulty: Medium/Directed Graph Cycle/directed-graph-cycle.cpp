class Solution {
  private:
    bool dfscheck(int node, vector<vector<int>> &adj, vector<int>& vis, vector<int>& pathvis){
        vis[node] = 1;
        pathvis[node] = 1;
        
        // traversing the graph
        for(auto x : adj[node]){
            // when the node is not visited
            if(!vis[x]){
                if(dfscheck(x, adj, vis, pathvis) == true){
                    return true;
                }
            }
            // if the node is visited but the path is not in order(cyclic)
            else if(pathvis[x]){
                return true;
            }
        }
        pathvis[node] = 0;
        return false;
    }  
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj(V);
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);
        }
        
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfscheck(i, adj, vis, pathvis) == true) return true;
            }
        }
        
        return false;
    }
};