//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void solveNQueens(int col, int n, vector<int>& board, vector<bool>& usedRow, vector<bool>& usedDiag1, vector<bool>& usedDiag2, vector<vector<int>>& results) {
        if (col == n) {
            results.push_back(board);
            return;
        }
        
        for (int row = 0; row < n; row++) {
            if (!usedRow[row] && !usedDiag1[row + col] && !usedDiag2[row - col + n - 1]) {
                board[col] = row + 1;
                usedRow[row] = usedDiag1[row + col] = usedDiag2[row - col + n - 1] = true;
                solveNQueens(col + 1, n, board, usedRow, usedDiag1, usedDiag2, results);
                usedRow[row] = usedDiag1[row + col] = usedDiag2[row - col + n - 1] = false;
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> results;
        vector<int> board(n);
        vector<bool> usedRow(n, false);
        vector<bool> usedDiag1(2 * n - 1, false);
        vector<bool> usedDiag2(2 * n - 1, false);
        
        solveNQueens(0, n, board, usedRow, usedDiag1, usedDiag2, results);
        return results;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if (ans.size() == 0)
            cout << -1 << "\n";
        else {
            sort(ans.begin(), ans.end());
            for (int i = 0; i < ans.size(); i++) {
                cout << "[";
                for (int u : ans[i])
                    cout << u << " ";
                cout << "] ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends