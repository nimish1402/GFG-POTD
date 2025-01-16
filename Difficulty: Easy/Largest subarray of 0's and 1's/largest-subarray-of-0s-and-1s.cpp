//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxLen(vector<int> &nums) {
        
        unordered_map<int, int> prefixSumIndex;
        int prefixSum = 0, maxLength = 0;
    
        // Initialize the hash map for prefix sum = 0 at index -1
        prefixSumIndex[0] = -1;
    
        for (int i = 0; i < nums.size(); ++i) {
            // Replace 0 with -1
            prefixSum += (nums[i] == 0) ? -1 : 1;
    
            // Check if this prefix sum was seen before
            if (prefixSumIndex.find(prefixSum) != prefixSumIndex.end()) {
                // Calculate the length of the subarray
                maxLength = max(maxLength, i - prefixSumIndex[prefixSum]);
            } else {
                // Store the first occurrence of this prefix sum
                prefixSumIndex[prefixSum] = i;
            }
        }
    
        return maxLength;
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore(); // To ignore the newline character after reading T

    while (T--) {
        string line;
        getline(cin, line); // Read the whole line for the array

        // Convert the line into an array of integers
        stringstream ss(line);
        vector<int> a;
        int num;
        while (ss >> num) {
            a.push_back(num);
        }

        // Create the solution object
        Solution obj;

        // Call the maxLen function and print the result
        cout << obj.maxLen(a) << endl;
    }

    return 0;
}
// } Driver Code Ends