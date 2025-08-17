class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        vector<pair<int, int>> diffIndex;
        for(int i = 0; i < arr.size(); i++) {
            diffIndex.push_back({abs(arr[i] - x), i});
        }
        
        // Sort based on difference, maintaining stability for equal differences
        stable_sort(diffIndex.begin(), diffIndex.end());
        
        // Create a copy of original array
        vector<int> temp = arr;
        
        // Rearrange array according to sorted differences
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = temp[diffIndex[i].second];
        }
        
    }
};