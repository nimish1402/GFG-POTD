//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int num, int i) {
            // Convert 1-based index to 0-based
        int bitIndex = i - 1;
    
        // Get the ith bit
        int ithBit = (num >> bitIndex) & 1;
    
        // Set the ith bit
        unsigned int setBit = num | (1 << bitIndex);
    
        // Clear the ith bit
        unsigned int clearBit = num & ~(1 << bitIndex);
    
        // Print the results
        cout << ithBit << " " << setBit << " " << clearBit;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends