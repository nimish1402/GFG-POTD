//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void generateHelper(int n, string current, vector<string>& result) {
    // Base case: if the current string length equals N, add it to the result
        if (current.length() == n) {
            result.push_back(current);
            return;
        }
        
        // Add '0' to the current string and recurse
        generateHelper(n, current + "0", result);
        
        // Add '1' to the current string and recurse only if the last character isn't '1'
        if (current.empty() || current.back() != '1') {
            generateHelper(n, current + "1", result);
        }
    }
    vector<string> generateBinaryStrings(int N){
        vector<string> result;
        generateHelper(N, "", result);
        return result;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends