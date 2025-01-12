//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxWater(vector<int> &height) {
       int n = height.size();
    if (n <= 1) return 0;

    int left = 0, right = n - 1;
    int left_max = 0, right_max = 0;
    int water_trapped = 0;

    while (left <= right) {
        if (height[left] < height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left]; // Update left_max
            } else {
                water_trapped += left_max - height[left]; // Calculate water trapped
            }
            left++;
        } else {
            if (height[right] >= right_max) {
                right_max = height[right]; // Update right_max
            } else {
                water_trapped += right_max - height[right]; // Calculate water trapped
            }
            right--;
        }
    }

    return water_trapped;
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends