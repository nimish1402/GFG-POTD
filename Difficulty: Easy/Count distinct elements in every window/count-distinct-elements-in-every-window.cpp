//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        
        vector<int> result;
        unordered_map<int, int> freqMap; // Map to store the frequency of elements in the current window
        int distinctCount = 0;
    
        // Process the first window
        for (int i = 0; i < k; ++i) {
            if (freqMap[arr[i]] == 0) {
                distinctCount++;
            }
            freqMap[arr[i]]++;
        }
        result.push_back(distinctCount);
    
        // Slide the window across the array
        for (int i = k; i < arr.size(); ++i) {
            // Remove the leftmost element of the previous window
            if (freqMap[arr[i - k]] == 1) {
                distinctCount--;
            }
            freqMap[arr[i - k]]--;
    
            // Add the new element in the current window
            if (freqMap[arr[i]] == 0) {
                distinctCount++;
            }
            freqMap[arr[i]]++;
    
            result.push_back(distinctCount);
        }
    
        return result;
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution obj;
        vector<int> res = obj.countDistinct(arr, k);
        for (auto it : res)
            cout << it << " ";
        cout << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends