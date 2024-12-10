//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    int floorSqrt(int n) {
        if (n == 1) return 1; // Special case

        int  low = 1;
        int high = n/2;
        int ans = 0;
        
        while(low<= high){
            int mid = low + (high-low) / 2;
            long long square = (long long)mid * mid;
            
            if(square == n) {return mid;}
            
            else if(square<n){
                ans = mid;
                low = mid + 1;
            }
            
            else{
                high = mid -1;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends