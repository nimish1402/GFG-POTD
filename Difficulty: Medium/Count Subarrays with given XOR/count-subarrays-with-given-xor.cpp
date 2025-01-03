//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        unordered_map<int, int> prefixXorCount;
    int currentXor = 0;
    int count = 0;

    // Initialize the map with prefixXor 0 having count 1 (empty subarray case)
    prefixXorCount[0] = 1;

    // Traverse through the array
    for (int num : arr) {
        // Update currentXor with the current number
        currentXor ^= num;

        // Check if currentXor ^ k exists in the map
        if (prefixXorCount.find(currentXor ^ k) != prefixXorCount.end()) {
            count += prefixXorCount[currentXor ^ k];
        }

        // Update the map with the current cumulative XOR
        prefixXorCount[currentXor]++;
    }

    return count;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends