//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> removeDuplicate(vector<int>& arr) {
        
        bool seen[101] = {false}; // Since 2 <= arr[i] <= 100
        int result_index = 0; // Index to place unique elements in arr
        
        for (int i = 0; i < arr.size(); i++) {
            if (!seen[arr[i]]) { // If the element hasn't been encountered before
                seen[arr[i]] = true; // Mark it as seen
                arr[result_index] = arr[i]; // Place it at the next unique position
                result_index++; // Move to the next position
            }
        }
        
        // Resize arr to contain only the unique elements
        arr.resize(result_index);
        return arr;
    }
    
    //  2 2 3 3 7 5
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        vector<int> ans = obj.removeDuplicate(arr);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends