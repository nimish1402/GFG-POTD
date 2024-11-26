//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    int findFloor(vector<int>& arr, int k) {

        int low = 0;
        int high = arr.size() -1;
        int result = -1;
        
        while (low <= high){
            int mid = low + (high - low) / 2;
            
            if (arr[mid] <= k) {
                // Update the result with the current mid as a potential floor
                result = mid;
                // Move to the right to find a larger valid element
                low = mid + 1;
            } else {
                // Move to the left to find a smaller valid element
                high = mid - 1;
            }
        }
        return result;
    }
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
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        Solution ob;
        int ans = ob.findFloor(arr, k);

        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends