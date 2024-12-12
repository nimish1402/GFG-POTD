//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
        // code hereclass Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int low = 0, high = arr.size() - 1;
        int firstIndex = -1, lastIndex = -1;
    
        // Find the first occurrence
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                firstIndex = mid;
                high = mid - 1; // Continue searching left
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        // Find the last occurrence
        low = 0;
        high = arr.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] == target) {
                lastIndex = mid;
                low = mid + 1; // Continue searching right
            } else if (arr[mid] < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
    
        // If the target is not found, return 0
        if (firstIndex == -1 || lastIndex == -1) {
            return 0;
        }
    
        // Return the count of occurrences
        return lastIndex - firstIndex + 1;
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
        int ans = ob.countFreq(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends