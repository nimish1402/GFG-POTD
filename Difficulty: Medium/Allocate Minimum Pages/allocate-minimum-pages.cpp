//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(vector<int> &arr, int n, int k, int mid) {
        int studentCount = 1, currentSum = 0;
        
        // Iterate over the books and assign them to students
        for (int i = 0; i < n; i++) {
            // If adding the current book exceeds the mid limit, allocate to a new student
            if (currentSum + arr[i] > mid) {
                studentCount++;
                currentSum = arr[i]; // Start with the current book
                // If number of students exceeds k, return false
                if (studentCount > k) return false;
            } else {
                currentSum += arr[i];
            }
        }
        return true;
    }

    int findPages(vector<int> &arr, int k) {
        int n = arr.size();
        
        // If there are fewer books than students, it's not possible to allocate
        if (n < k) return -1;

        int low = *max_element(arr.begin(), arr.end()); // Maximum number of pages in a single book
        int high = accumulate(arr.begin(), arr.end(), 0); // Sum of all book pages

        int result = high;
        
        // Binary search to find the smallest maximum number of pages
        while (low <= high) {
            int mid = (low + high) / 2;
            
            // Check if it's possible to allocate books such that no student gets more than 'mid' pages
            if (isPossible(arr, n, k, mid)) {
                result = mid; // Update result
                high = mid - 1; // Try for a smaller maximum number of pages
            } else {
                low = mid + 1; // Increase the minimum number of pages
            }
        }
        
        return result;
    }
};

//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends