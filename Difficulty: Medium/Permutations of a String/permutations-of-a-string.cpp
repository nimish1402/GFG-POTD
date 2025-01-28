//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  void backtrack(string& s, int index, set<string>& result) {
        if (index == s.size()) {
            result.insert(s);  // Add the current permutation to the set
            return;
        }
        for (int i = index; i < s.size(); ++i) {
            swap(s[index], s[i]);  // Swap the current character with the one at index `i`
            backtrack(s, index + 1, result);  // Recur for the next index
            swap(s[index], s[i]);  // Backtrack (undo the swap)
        }
    }
    vector<string> findPermutation(string &s) {
        set<string> result;
        backtrack(s, 0, result);
    
        // Convert the set of unique permutations to a vector
        return vector<string>(result.begin(), result.end());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        vector<string> ans = ob.findPermutation(S);
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends