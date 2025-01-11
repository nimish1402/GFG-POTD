//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
      unordered_set<char> seen; // To store unique characters in the current window
        int maxLength = 0;
        int start = 0; // Left pointer of the window
    
        for (int end = 0; end < s.length(); ++end) {
            // Shrink the window until the character at `end` becomes unique
            while (seen.find(s[end]) != seen.end()) {
                seen.erase(s[start]);
                start++;
            }
            // Add the current character to the set
            seen.insert(s[end]);
            // Update the maximum length
            maxLength = max(maxLength, end - start + 1);
        }
    
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends