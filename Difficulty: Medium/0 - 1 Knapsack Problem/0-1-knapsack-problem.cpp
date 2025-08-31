class Solution {
  public:
    int fn(int ind, int w, vector<int> &wt, vector<int> &val, vector<vector<int>> &dp){
        if(ind == 0){
            if(wt[0] <= w) return val[0];
            return 0;
            
        }
        
        if(dp[ind][w] != -1) return dp[ind][w];
        int nottake = 0 + fn(ind-1, w, wt, val, dp);
        int take = INT_MIN;
        if(wt[ind] <= w){
            take = val[ind] + fn(ind-1, w-wt[ind], wt, val, dp);
        }
        
        return dp[ind][w] = max(take, nottake);
        
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        int m = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return fn(n-1, W, wt, val, dp);
        
    }
};  