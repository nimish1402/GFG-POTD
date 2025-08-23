// User function Template for C++

class Solution {
  public:
    int fn(int i, int j, vector<vector<int>>& a, vector<vector<int>>& dp ){
        int m = a[0].size();
        if(j < 0 || j >= m) return -1e8;
        if(i == 0) return a[0][j];
        if(dp[i][j] != -1) return dp[i][j];
        
        int up =  fn(i-1, j , a, dp);
        int ld = fn(i-1, j-1, a, dp);
        int rd = fn(i-1, j+1 , a, dp);
        
        return dp[i][j] = a[i][j] + max(up, max(ld, rd));
    }
    
    int maximumPath(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        int maxi = -1e8;
        vector<vector<int>> dp(n, vector<int>(m, -1));
        for(int j = 0; j < m; j++){
            maxi = max(maxi, fn(n-1, j, a, dp));
        }
        return maxi;
        
    } 
};