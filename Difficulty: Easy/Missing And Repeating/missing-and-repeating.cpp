//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
       int n = arr.size();
    int repeating = -1, missing = -1;

    // Step 1: Traverse the array and mark visited indices
    for (int i = 0; i < n; ++i) {
        int index = std::abs(arr[i]) - 1; // Convert value to index (1-based to 0-based)

        if (arr[index] < 0) {
            // If already negative, this index corresponds to the repeating number
            repeating = std::abs(arr[i]);
        } else {
            // Mark the index as visited by negating the value
            arr[index] = -arr[index];
        }
    }

    // Step 2: Find the missing number
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            // Positive value means index + 1 is the missing number
            missing = i + 1;
            break;
        }
    }

    return {repeating, missing};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        int num;
        vector<int> arr;
        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        auto ans = ob.findTwoElement(arr);
        cout << ans[0] << " " << ans[1] << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends