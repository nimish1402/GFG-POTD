//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        long long count = 0;
        int left = 0;
        int right = arr.size() - 1;
        
        while (left < right) {
            int sum = arr[left] + arr[right];
            
            if (sum == target) {
                if (arr[left] == arr[right]) {
                    // For same elements
                    long long len = right - left + 1;
                    count += (len * (len - 1)) / 2;
                    break;
                } else {
                    // Count duplicates on left side
                    int leftCount = 1;
                    while (left + 1 < right && arr[left] == arr[left + 1]) {
                        leftCount++;
                        left++;
                    }
                    
                    // Count duplicates on right side
                    int rightCount = 1;
                    while (right - 1 > left && arr[right] == arr[right - 1]) {
                        rightCount++;
                        right--;
                    }
                    
                    count += (long long)leftCount * rightCount;
                    left++;
                    right--;
                }
            }
            else if (sum < target) {
                left++;
            }
            else {
                right--;
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int target;
        string input;
        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        cin >> target;
        cin.ignore();
        Solution obj;
        cout << obj.countPairs(arr, target) << endl;
        cout << "~\n";
    }

    return 0;
}
// } Driver Code Ends