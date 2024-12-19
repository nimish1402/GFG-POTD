//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        
        int missingCount = 0; // Tracks how many numbers are missing
    int current = 1;      // Start from 1
    int index = 0;        // Pointer for array traversal

        while (missingCount < k) {
        if (index < arr.size() && arr[index] == current) {
            // If the current number is in the array, skip it
            index++;
        } else {
            // If the current number is missing, increment the count
            missingCount++;
        }
        if (missingCount < k) {
            current++; // Move to the next number
        }
    }

    return current; // Return the kth missing number

    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.kthMissing(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends