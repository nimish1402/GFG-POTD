//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    vector<int> sumClosest(vector<int>& arr, int target) {
        int n = arr.size();
        
        // If array has less than 2 elements, return empty array
        if (n < 2) {
            return {};
        }
        
        // Sort the array
        std::sort(arr.begin(), arr.end());
        
        int left = 0, right = n - 1;
        int minDiff = INT_MAX;
        
        // Variables to store potential pairs
        std::vector<std::pair<int, int>> candidates;
        
        // Two pointer approach
        while (left < right) {
            int currentSum = arr[left] + arr[right];
            int currentDiff = abs(currentSum - target);
            
            // If we found a closer sum
            if (currentDiff <= minDiff) {
                if (currentDiff < minDiff) {
                    candidates.clear();
                }
                candidates.push_back({arr[left], arr[right]});
                minDiff = currentDiff;
            }
            
            // Move pointers based on sum comparison
            if (currentSum < target) {
                left++;
            } else if (currentSum > target) {
                right--;
            } else {
                left++;
                right--;
            }
        }
        
        // If no pairs found (shouldn't happen given constraints)
        if (candidates.empty()) {
            return {};
        }
        
        // Find pair with maximum absolute difference
        int maxDiff = 0;
        std::pair<int, int> result = candidates[0];
        
        for (const auto& pair : candidates) {
            int diff = abs(pair.second - pair.first);
            if (diff > maxDiff) {
                maxDiff = diff;
                result = pair;
            }
        }
        
        return {result.first, result.second};
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
        int target = stoi(ks);
        Solution ob;
        vector<int> ans = ob.sumClosest(arr, target);
        if (ans.empty()) {
            cout << "[]";
        } else {
            for (auto it : ans) {
                cout << it << " ";
            }
        }
        cout << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends