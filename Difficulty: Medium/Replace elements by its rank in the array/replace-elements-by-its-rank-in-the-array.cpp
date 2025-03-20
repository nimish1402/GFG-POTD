//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(int i = 0; i < N; i++ ){
            pq.push({arr[i], i});
        }
        
        vector<int> rankarr(N);
        int rank = 0, prev = -1;
        
        while(!pq.empty()){
            pair<int, int> topelement = pq.top();
            pq.pop();
            
            int value = topelement.first;
            int index = topelement.second;
            
            if(value!= prev){
                rank++;
            }
            
            rankarr[index] = rank;
            prev = value;
        }
        return rankarr;
    }

};



//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends