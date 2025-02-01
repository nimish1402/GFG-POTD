//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {   
        long long xor_all = 0;
        for (int i = 0; i < N; i++) {
            xor_all ^= Arr[i];
        }
    
        // Step 2: Find the rightmost set bit (differentiating bit)
        long long rightmost_set_bit = xor_all & (-xor_all);
    
        long long num1 = 0, num2 = 0;
    
        // Step 3: Divide numbers into two buckets and XOR within each
        for (int i = 0; i < N; i++) {
            if (Arr[i] & rightmost_set_bit)
                num1 ^= Arr[i];  // Bucket 1
            else
                num2 ^= Arr[i];  // Bucket 2
        }
    
        // Step 4: Return the numbers in decreasing order
        if (num1 < num2) swap(num1, num2);
        return {num1, num2};
        }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends