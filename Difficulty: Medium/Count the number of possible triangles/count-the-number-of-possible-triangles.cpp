//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the number of possible triangles.
    int countTriangles(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;
        
        // Sort the array in ascending order
        sort(arr.begin(), arr.end());
        
        int count = 0;
        
        // Fix the greatest side first
        // Then use two pointer approach for remaining two sides
        for (int i = n - 1; i >= 2; i--) {
            int left = 0;
            int right = i - 1;
            
            // For current i, find all pairs (left, right) such that
            // arr[left] + arr[right] > arr[i]
            while (left < right) {
                // If sum of two sides is greater than third side
                if (arr[left] + arr[right] > arr[i]) {
                    // All elements between left and right will also form triangles
                    count += right - left;
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.countTriangles(a) << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends