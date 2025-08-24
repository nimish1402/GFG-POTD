class Solution {
  public:
    
    bool fn(int index, int target, vector<int>& arr, vector<vector<int>>& dp){
        if(target == 0) return true;
        if(index == 0) return (arr[index] == target);
        
        if(dp[index][target] != -1) return dp[index][target];
        bool nottake = fn(index -1 , target, arr, dp);
        bool take = false;
        if(target >= arr[index]){
            take = fn(index -1 , target - arr[index], arr, dp);
        }
        
        return dp[index][target] = (nottake || take);
        
    }
    bool isSubsetSum(vector<int>& arr, int sum) {
        vector<vector<int>> dp(arr.size(), vector<int>(sum+1, -1));
        return fn( arr.size() - 1, sum, arr, dp);    
    }
};