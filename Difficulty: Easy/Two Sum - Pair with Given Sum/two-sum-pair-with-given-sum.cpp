//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool twoSum(vector<int>& arr, int x) {
        unordered_map<int, int> umap;
            for(int i=0;i<arr.size();i++){
                umap[arr[i]]++;
            }
            for(auto itr = umap.begin(); itr!=umap.end(); itr++){
                int key = itr->first;
                int val = itr->second;
                
                int pair = x-key;
                if(pair==key) {
                    if(val>1){
                        return true;
                    }
                }
                else{
                    if(umap.find(pair)!=umap.end())
                    return true;
                }
            }return false;    
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int x;
        cin >> x;
        cin.ignore();

        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.twoSum(arr, x);
        cout << (ans ? "true" : "false") << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends