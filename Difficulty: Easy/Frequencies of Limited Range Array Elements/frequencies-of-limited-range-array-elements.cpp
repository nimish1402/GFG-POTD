//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to count the frequency of all elements from 1 to N in the array.
    void frequencyCount(vector<int>& arr, int N, int P) {
        vector<int> freq(N, 0);

    // Step 2: Traverse the array and update the frequency count
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] >= 1 && arr[i] <= N) {
                freq[arr[i] - 1]++;  // Increment the count for arr[i]
            }
        }
    
        // Step 3: Modify the original array to store the frequencies
        for (int i = 0; i < N; i++) {
            arr[i] = freq[i];  // Update the array with the frequencies
        }
    
        // Step 4: For elements beyond n, set them to 0
        for (int i = N; i < arr.size(); i++) {
            arr[i] = 0;  // Set the remaining elements to 0
        }
    } 
};


//{ Driver Code Starts.

int main() {
    long long t;

    // testcases
    cin >> t;

    while (t--) {

        int N, P;
        // size of array
        cin >> N;

        vector<int> arr(N);

        // adding elements to the vector
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        cin >> P;
        Solution ob;
        // calling frequncycount() function
        ob.frequencyCount(arr, N, P);

        // printing array elements
        for (int i = 0; i < N; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends