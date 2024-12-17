//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

    int aggressiveCows(vector<int> &stalls, int k) {
        // Sort the stalls to prepare for binary search
        sort(stalls.begin(), stalls.end());
        int n = stalls.size();

        // Define the search space for minimum distance
        int low = 1, high = stalls[n - 1] - stalls[0], result = 0;

        // Perform binary search
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Check if it is possible to place cows with the current distance
            if (canPlaceCows(stalls, k, mid)) {
                result = mid; // Record the valid distance
                low = mid + 1; // Try for a larger distance
            } else {
                high = mid - 1; // Try for a smaller distance
            }
        }

        return result;
    }

  private:

    bool canPlaceCows(vector<int> &stalls, int k, int minDist) {
        int cowsPlaced = 1; // Place the first cow in the first stall
        int lastPos = stalls[0];

        // Place the remaining cows
        for (int i = 1; i < stalls.size(); i++) {
            if (stalls[i] - lastPos >= minDist) {
                cowsPlaced++;
                lastPos = stalls[i];
                if (cowsPlaced == k) {
                    return true; // All cows placed successfully
                }
            }
        }

        return false; // Not all cows could be placed
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int k;
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string in;
        getline(cin, in);
        stringstream sss(in);
        int num;
        while (sss >> num) {
            k = num;
        }
        Solution ob;
        int ans = ob.aggressiveCows(arr, k);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends