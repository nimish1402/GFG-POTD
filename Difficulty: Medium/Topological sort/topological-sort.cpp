class Solution {
  private:
    void dfs(int node, vector<int>& vis, stack<int>& st, const vector<vector<int>>& adj){
        
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
        }
        
        // indegree array 
        vector<int> indegree(V, 0);
        for(int i = 0; i < V; i++){
            for(auto it: adj[i]){
                indegree[it]++;
            }
        }
        
        queue<int> q;
        
        for(int i = 0; i < V; i++){
            if(indegree[i] == 0){
                q.push(i);        
            }
        }
        vector<int> topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            
            for(auto it: adj[node]){
                indegree[it]--;
                if(indegree[it] == 0) q.push(it);
            }
        }
        
        return topo;
    }
};