//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    
    bool dfs(vector<vector<char>>& mat, int x, int y, string& word, int index, vector<vector<bool>>& visited) {
        if (index == word.size()) return true; // If all characters are matched, return true
    
        int n = mat.size();
        int m = mat[0].size();
    
        if (x < 0 || y < 0 || x >= n || y >= m || visited[x][y] || mat[x][y] != word[index])
            return false; // If out of bounds, visited, or character mismatch, return false
    
        // Mark the cell as visited
        visited[x][y] = true;
    
        // Explore all 4 possible directions
        for (int d = 0; d < 4; ++d) {
            int newX = x + dx[d];
            int newY = y + dy[d];
    
            if (dfs(mat, newX, newY, word, index + 1, visited)) {
                return true;
            }
        }
    
        // Backtrack
        visited[x][y] = false;
        return false;
    }

    bool isWordExist(vector<vector<char>>& mat, string& word) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
    
        // Start DFS from every cell that matches the first letter of the word
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == word[0]) {
                    if (dfs(mat, i, j, word, 0, visited)) {
                        return true;
                    }
                }
            }
        }
    
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends