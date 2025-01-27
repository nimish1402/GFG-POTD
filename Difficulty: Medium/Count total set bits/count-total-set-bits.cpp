//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        int count = 0;
        for (int i = 0; (1 << i) <= n; ++i) { // Iterate over each bit position
            int blockSize = 1 << (i + 1); // Size of a segment: 2^(i+1)
            int fullBlocks = n / blockSize; // Number of full blocks
            count += fullBlocks * (blockSize / 2); // Add set bits from full blocks
    
            // Handle remaining numbers in the last incomplete block
            int remainder = n % blockSize;
            count += max(0, remainder - (blockSize / 2) + 1);
        }
        return count;
    }
};


//{ Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  
cout << "~" << "\n";
}
	  return 0;
}

// } Driver Code Ends