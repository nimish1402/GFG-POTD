// User function template for C++

class Solution {
  public:
    void floydWarshall(vector<vector<int>> &dist) {
       
       int n = dist.size();
       
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    // Avoid overflow by checking if either intermediate distance is infinity
                    if (dist[i][k] != 100000000 && dist[k][j] != 100000000) {
                        if (dist[i][j] > dist[i][k] + dist[k][j]) {
                            dist[i][j] = dist[i][k] + dist[k][j];
                        }
                    }
                }
            }
        }
       
    }
};