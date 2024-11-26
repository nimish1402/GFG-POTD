//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        int floor = -1; // Default floor value
        int ceil = -1;  // Default ceiling value

        for (int num : arr) {
            // Update floor if num is smaller than or equal to x
            if (num <= x && num > floor) {
                floor = num;
            }

            // Update ceiling if num is greater than or equal to x
            if (num >= x && (ceil == -1 || num < ceil)) {
                ceil = num;
            }
        }

        return {floor, ceil};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n~\n";
    }
    return 0;
}
// } Driver Code Ends