class Solution {
  public:
    int mod = (int)(1e9 + 7);
    
    int fn(int index, int sum, vector<int> &num, vector<vector<int>>&dp){
        if(index == 0) {
            if(sum == 0 && num[0] == 0) return 2;
            if(sum == 0 || sum == num[0]) return 1;
            return 0;
        }
        
        if(dp[index][sum]!= -1) return dp[index][sum];
        
        int nottake = fn(index-1, sum, num, dp);
        int take = 0;
        if(num[index] <= sum){
            take = fn(index-1, sum - num[index], num, dp);
        }
        return dp[index][sum] = (take+nottake) % mod;
    }
    
    int findways(vector<int>& arr, int target){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target +1, -1));
        return fn(n-1, target, arr, dp );
    }
    
    int countPartitions(vector<int>& arr, int d) {
        
        int totsum = 0;
        for(auto &it : arr){
            totsum += it;
        }
        
        if(totsum -d < 0 || (totsum - d) % 2 ) return false;
        return findways(arr, (totsum - d) / 2);
        
    }
};