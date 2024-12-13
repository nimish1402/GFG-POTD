//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findMin(vector<int>& arr) {
        int left = 0;
        int right = arr.size() - 1;
    
        // If the array is not rotated (first element is the smallest)
        if (arr[left] <= arr[right]) {
            return arr[left];
        }
    
        while (left <= right) {
            int mid = left + (right - left) / 2;
    
            // Check if mid is the minimum element
            if (mid > 0 && arr[mid] < arr[mid - 1]) {
                return arr[mid];
            }
    
            // Check if mid+1 is the minimum element
            if (mid < arr.size() - 1 && arr[mid] > arr[mid + 1]) {
                return arr[mid + 1];
            }
    
            // Decide which half to search
            if (arr[mid] >= arr[left]) {
                left = mid + 1; // Go to the right half
            } else {
                right = mid - 1; // Go to the left half
            }
        }
        return -1;

    }
    
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    Solution ob;
    while (t--) {
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        cout << ob.findMin(nums) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends