//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution {
  public:
    int minJumps(vector<int>& arr) {
        
        int n = arr.size();
    
        // If the array has only one element, we are already at the end
        if (n <= 1) return 0;
    
        // If the first element is 0, we cannot make any jumps
        if (arr[0] == 0) return -1;
    
        // Initialize variables
        int jumps = 0;       // To keep track of the number of jumps
        int current_end = 0; // To track the end of the current jump range
        int farthest = 0;    // To track the farthest point reachable from the current jump range
    
        // Traverse the array
        for (int i = 0; i < n - 1; i++) {
            // Update the farthest point reachable from current index
            farthest = max(farthest, i + arr[i]);
    
            // If we have reached the end of the range of the current jump
            if (i == current_end) {
                jumps++; // Increment the jump count
                current_end = farthest; // Set the end of the current jump range to farthest reachable point
                
                // If the current end reaches or exceeds the last index, we are done
                if (current_end >= n - 1) return jumps;
            }
        }
    
        // If we end the loop and have not reached the end of the array
        return -1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, i, j;
        vector<int> arr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        cout << obj.minJumps(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends