//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size();    // Number of rows
        int m = mat[0].size(); // Number of columns
        
        // Start from the top-right corner
        int row = 0, col = m - 1;
        
        // Traverse the matrix
        while (row < n && col >= 0) {
            if (mat[row][col] == x) {
                return true; // Element found
            }
            if (mat[row][col] > x) {
                col--; // Move left if the current value is greater than x
            } else {
                row++; // Move down if the current value is smaller than x
            }
        }
        
        // If we exhaust the search, the element is not present
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends