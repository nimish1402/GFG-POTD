//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

const int MOD = 1e9 + 7;

class Solution {
  public:

    int Maximize(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        
        // Initialize result
        long long result = 0;
        
        // Calculate the sum
        for (int i = 0; i < arr.size(); ++i) {
            result = (result + (long long)arr[i] * i) % MOD;
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
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends