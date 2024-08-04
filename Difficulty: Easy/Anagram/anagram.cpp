//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b) {

        if (a.length() != b.length()) {
        return false;
    }

        // Initialize frequency counters for both strings
        std::vector<int> count_a(26, 0); // For 'a' to 'z'
        std::vector<int> count_b(26, 0); // For 'a' to 'z'
    
        // Update the frequency counters for each character in both strings
        for (char char_a : a) {
            count_a[char_a - 'a']++;
        }
        for (char char_b : b) {
            count_b[char_b - 'a']++;
        }
    
        // Compare frequency counts of both strings
        for (int i = 0; i < 26; i++) {
            if (count_a[i] != count_b[i]) {
                return false;
            }
        }
    
        return true;
    
    }
};

//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {
        string c, d;

        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

// } Driver Code Ends