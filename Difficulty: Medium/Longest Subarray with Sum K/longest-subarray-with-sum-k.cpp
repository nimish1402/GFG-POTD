//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        unordered_map<int, int> prefixSumMap; // To store prefix sums and their earliest indices
        int maxLength = 0;
        int prefixSum = 0;
    
        for (int i = 0; i < arr.size(); ++i) {
            // Add current element to prefix sum
            prefixSum += arr[i];
    
            // Case 1: If the prefix sum is equal to k, update maxLength
            if (prefixSum == k) {
                maxLength = i + 1;
            }
    
            // Case 2: Check if there's a prefix sum that makes the subarray sum equal to k
            if (prefixSumMap.find(prefixSum - k) != prefixSumMap.end()) {
                maxLength = max(maxLength, i - prefixSumMap[prefixSum - k]);
            }
    
            // Case 3: Store the prefix sum in the map if it doesn't already exist
            if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) {
                prefixSumMap[prefixSum] = i;
            }
        }
    
        return maxLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int k;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> k;
        cin.ignore(); // Ignore newline character after k input

        Solution solution;
        cout << solution.longestSubarray(arr, k) << "\n";
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends