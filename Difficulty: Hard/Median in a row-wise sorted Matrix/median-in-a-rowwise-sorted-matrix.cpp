//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    
    int upperbound(vector<int>& arr, int x, int n){
        int low =0,high = n-1;
        int ans = n;
        
        while(low<= high){
            int mid = (low +high) / 2;
            
            if(arr[mid] > x){
            
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
            
        }
        return ans ;
        
    }
    
    int countSmallEqual(vector<vector<int>>& matrix, int m , int n, int x){
        
        int cnt = 0;
        for(int i = 0; i<m; i++){
            cnt += upperbound(matrix[i], x, n);
        }
        
        return cnt;
    }
    
    int median(vector<vector<int>> &matrix) {
        int low = INT_MAX, high = INT_MIN;
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i =0; i<m; i++){
            low = min(low, matrix[i][0]);
            high = max(high, matrix[i][n-1]);
            
        }
        
        int req = (n*m) / 2;
        while(low<= high){
            int mid = (low + high) / 2;
            int smallEqual = countSmallEqual(matrix, m,n,mid);
            if(smallEqual <= req) low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                cin >> matrix[i][j];
        Solution obj;
        int ans = -1;
        ans = obj.median(matrix);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends