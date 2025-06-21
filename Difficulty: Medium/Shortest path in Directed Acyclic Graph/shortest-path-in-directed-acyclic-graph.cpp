// User function Template for C++
class Solution {
  private:
    void toposort(int node, vector<vector<pair<int,int>>>& adj, vector<int>& vis, stack<int>& st){
        vis[node] = 1;
        for(auto& it: adj[node]){
            int v = it.first;
            if(!vis[v]){
                toposort(v, adj, vis, st);
            }
        }
        
        
        st.push(node);
    }
  public:
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // STEP 1 create a graph
        vector<vector<pair<int,int>>> adj(N);
        
        for(int i = 0; i < M; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v, wt});
        }
        
        // find the topo sort 
        vector<int> vis(N, 0);
        stack<int> st;
        
        for(int i =0; i < N; i++){
            if(!vis[i]){
                toposort(i, adj, vis, st);
            }
        }
        
        // STEP 2 distance calculation
        vector<int> dist(N, -1);
        
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if (dist[node] != -1) {
            
                for(auto& it: adj[node]){
                    int v = it.first;
                    int wight = it.second;
                
                    if(dist[v] == -1 ||dist[node] + wight < dist[v]){
                        dist[v] = dist[node] + wight;
                    }
                }    
            }
            
        }
        return dist;
        
    }
};
