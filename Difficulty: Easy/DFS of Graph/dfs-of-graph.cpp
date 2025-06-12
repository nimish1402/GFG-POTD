class Solution {
  public:
  
    void dgfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& result){
    
        visited[node] = true;
        result.push_back(node);
        
        for(int neighbour : adj[node]){
            if(!visited[neighbour]){
                dgfs(neighbour, adj, visited, result);
            }
        }
    }
    
    
    vector<int> dfs(vector<vector<int>>& adj) {
        vector<int> result;
        int V = adj.size();
        vector<bool> visited(V, false);
        dgfs(0, adj, visited, result);
        return result;
        
    }
};