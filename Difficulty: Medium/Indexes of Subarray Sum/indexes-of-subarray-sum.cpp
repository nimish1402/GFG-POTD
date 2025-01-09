//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        int n = arr.size();
        int left = 0;  // Left pointer of the window
        long long currentSum = 0;  // Current sum of elements in the window
        
        // Iterate through the array using right pointer
        for (int right = 0; right < n; right++) {
            currentSum += arr[right];  // Add current element to sum
            
            // If current sum exceeds target, shrink window from left
            while (currentSum > target && left <= right) {
                currentSum -= arr[left];
                left++;
            }
            
            // If we found a subarray with required sum
            if (currentSum == target) {
                // Return 1-based indices
                return {left + 1, right + 1};
            }
        }
        
        // If no subarray found
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends