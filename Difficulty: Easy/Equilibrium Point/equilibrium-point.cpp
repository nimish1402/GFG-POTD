//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n = arr.size();

        if (n < 3) return -1; // Equilibrium point cannot exist in arrays smaller than size 3
    
        long long totalSum = 0, leftSum = 0;
    
        // Calculate total sum of the array
        for (int num : arr) {
            totalSum += num;
        }
    
        // Traverse the array to find the equilibrium point
        for (int i = 0; i < n; ++i) {
            // Right sum is totalSum - leftSum - arr[i]
            if (leftSum == totalSum - leftSum - arr[i]) {
                return i;
            }
            leftSum += arr[i];
        }
    
        return -1; // No equilibrium point found
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends