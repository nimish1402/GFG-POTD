//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        stack<int> s;
        
        
        for (int i = 0; i < n; i++) {
            s.push(i);
        }
        
        
        while (s.size() > 1) {
            int first = s.top();
            s.pop();
            int second = s.top();
            s.pop();
            
            if (mat[first][second] == 1) {
                // first knows second, so first can't be a celebrity
                s.push(second);
            } else {
                // first doesn't know second, so second can't be a celebrity
                s.push(first);
            }
        }
        
        int candidate = s.top();
        
        // Validate the candidate
        for (int i = 0; i < n; i++) {
            if (i != candidate && (mat[candidate][i] == 1 || mat[i][candidate] == 0)) {
                return -1;
            }
        }
        return candidate;
    
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends