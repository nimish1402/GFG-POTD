//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end()); // Sort the array
            int left = 0, right = arr.size() - 1;
            int count = 0;
        
            while (left < right) {
                int sum = arr[left] + arr[right];
                if (sum < target) {
                    count += (right - left); // All pairs between left and right satisfy the condition
                    left++; // Move the left pointer forward
                } else {
                    right--; // Move the right pointer backward
                }
            }
            return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);
        cout << res << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends