//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        
        unordered_map<int,int> map;
        int n = arr.size();
        
        if(n==1){
            return false;
        }
        
        for(int i =0; i<= k; i++){
            map[arr[i]]++;
            if(map[arr[i]] > 1){
                return true;
            }
        }
        
        int last =0;
        
        for(int i = k+1; i<n; i++){
            map[arr[last++]]--;
            map[arr[i]]++;
            if(map[arr[i]] > 1){
                return true;
            }
        }
        return false;
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
        Solution obj;
        bool res = obj.checkDuplicatesWithinK(arr, k);
        if (res)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        // cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends