//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countTriplets(vector<int> &arr, int target) {
            int n = arr.size();
            int count = 0;
            
            // Fix the first element arr[i]
            for(int i = 0; i < n - 2; i++) {
                int left = i + 1;
                int right = n - 1;
                
                while(left < right) {
                    int sum = arr[i] + arr[left] + arr[right];
                    
                    if(sum == target) {
                        if(arr[left] == arr[right]) {
                            // If left and right elements are same
                            int len = right - left + 1;
                            // nC2 combinations for selecting 2 positions from len positions
                            count += (len * (len - 1)) / 2;
                        } else {
                            // Count all elements equal to arr[left]
                            int left_count = 1;
                            int temp_left = left;
                            while(temp_left + 1 < right && arr[temp_left] == arr[temp_left + 1]) {
                                left_count++;
                                temp_left++;
                            }
                            
                            // Count all elements equal to arr[right]
                            int right_count = 1;
                            int temp_right = right;
                            while(temp_right - 1 > left && arr[temp_right] == arr[temp_right - 1]) {
                                right_count++;
                                temp_right--;
                            }
                            
                            count += left_count * right_count;
                        }
                        
                        // Move both pointers after counting
                        left++; 
                        right--;
                        
                        // Skip duplicates
                        while(left < right && arr[left] == arr[left - 1]) left++;
                        while(left < right && arr[right] == arr[right + 1]) right--;
                    }
                    else if(sum < target) {
                        left++;
                    }
                    else {
                        right--;
                    }
                }
            }
            
            return count;
    }
};

//{ Driver Code Starts.

vector<int> lineArray() {
    string line;
    getline(cin, line);
    stringstream ss(line);
    vector<int> arr;
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }
    return arr;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr = lineArray();
        int target;
        cin >> target;
        cin.ignore();

        Solution ob;
        int res = ob.countTriplets(arr, target);
        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends