//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> prefix_map;  // To store prefix sum frequencies
            int current_sum = 0;  // To store current prefix sum
            int count = 0;  // To store the number of subarrays whose sum is equal to k
            
            // Initialize the map with prefix sum 0 to handle the case when a subarray starts from index 0
            prefix_map[0] = 1;
            
            // Traverse the array
            for (int num : arr) {
                // Update the current prefix sum
                current_sum += num;
                
                // Check if there is any prefix sum such that current_sum - k exists
                if (prefix_map.find(current_sum - k) != prefix_map.end()) {
                    count += prefix_map[current_sum - k];  // Add the count of such subarrays
                }
                
                // Update the map with the current prefix sum
                prefix_map[current_sum]++;
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

        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.countSubarrays(arr, k);
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends