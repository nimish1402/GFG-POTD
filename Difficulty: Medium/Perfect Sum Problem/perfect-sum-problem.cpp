//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int mod = 1e9 + 7;
    
    int countSubsets(vector<int>& arr, int n, int sum, vector<vector<int>>& dp){
        if(dp[n][sum] != -1) return dp[n][sum];
        if(n == 0 and sum>0) return 0;
        
        else if(n ==1 ){
            if(sum==0){
                if(arr[0] == 0) return 2;
                else return 1;
            }
            else{
                if(arr[0] == sum) return 1;
                else return 0;
            }
            
        }
        else if(n == 0 and sum ==0) return 1;
        
        int ans = countSubsets(arr, n-1, sum, dp);
        
        if(arr[n-1] <= sum ){
            ans = ans + countSubsets(arr, n-1, sum-arr[n-1], dp);
            ans %= mod;
        }
        return dp[n][sum] = ans;
        
    }
    
    int perfectSum(vector<int>& arr, int sum) {
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(sum+1, -1));
        return countSubsets(arr, n, sum, dp) % mod;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends