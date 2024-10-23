//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        
        vector<int> unionResult;
    int i = 0, j = 0;

    // Traverse both arrays
    while (i < a.size() && j < b.size()) {
        // If the current element of a is smaller
        if (a[i] < b[j]) {
            if (unionResult.empty() || unionResult.back() != a[i]) {
                unionResult.push_back(a[i]);
            }
            i++;
        }
        // If the current element of b is smaller
        else if (b[j] < a[i]) {
            if (unionResult.empty() || unionResult.back() != b[j]) {
                unionResult.push_back(b[j]);
            }
            j++;
        }
        // If both elements are equal, add one of them and move both pointers
        else {
            if (unionResult.empty() || unionResult.back() != a[i]) {
                unionResult.push_back(a[i]);
            }
            i++;
            j++;
        }
    }

    // Add remaining elements of a
    while (i < a.size()) {
        if (unionResult.empty() || unionResult.back() != a[i]) {
            unionResult.push_back(a[i]);
        }
        i++;
    }

    // Add remaining elements of b
    while (j < b.size()) {
        if (unionResult.empty() || unionResult.back() != b[j]) {
            unionResult.push_back(b[j]);
        }
        j++;
    }

    return unionResult;;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a, b;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        // Read second array
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> number) {
            b.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.findUnion(a, b);
        for (int i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends