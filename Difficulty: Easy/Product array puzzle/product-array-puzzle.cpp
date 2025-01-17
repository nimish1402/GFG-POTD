//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return {1};
        }

        // Initialize arrays
        vector<int> left_products(n, 1);
        vector<int> right_products(n, 1);
        vector<int> result(n, 1);

        // Fill left_products array
        for (int i = 1; i < n; i++) {
            left_products[i] = nums[i - 1] * left_products[i - 1];
        }

        // Fill right_products array
        for (int j = n - 2; j >= 0; j--) {
            right_products[j] = nums[j + 1] * right_products[j + 1];
        }

        // Construct the result array
        for (int i = 0; i < n; i++) {
            result[i] = left_products[i] * right_products[i];
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

        Solution obj;
        vector<int> res = obj.productExceptSelf(arr);

        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends