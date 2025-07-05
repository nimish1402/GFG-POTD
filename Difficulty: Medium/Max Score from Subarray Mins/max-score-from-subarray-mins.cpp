class Solution {
  public:
    int maxSum(vector<int> &arr) {
        
        int maxi= 0;
        for(int i = 0; i < arr.size() - 1; i++){
            int sum = arr[i] + arr[i+1];
            maxi = max(sum, maxi);
        }
        return maxi;
        
    }
};