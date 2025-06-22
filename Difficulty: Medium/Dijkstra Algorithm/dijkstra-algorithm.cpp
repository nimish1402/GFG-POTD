// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        // creating a adj list 
        vector<vector<int>> adj[V];
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }
        // solution 
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V, 1e9);
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int adjNode = it[0];
                int edgeweight = it[1];
                
                if(dis + edgeweight < dist[adjNode]){
                    dist[adjNode] = dis + edgeweight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};