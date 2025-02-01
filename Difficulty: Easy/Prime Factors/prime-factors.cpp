//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	vector<int>AllPrimeFactors(int N) {
	    vector<int> primeFactors;

    // Check for factor 2
        if (N % 2 == 0) {
            primeFactors.push_back(2);
            while (N % 2 == 0) {
                N /= 2;
            }
        }
    
        // Check for odd factors from 3 to sqrt(N)
        for (int i = 3; i * i <= N; i += 2) {
            if (N % i == 0) {
                primeFactors.push_back(i);
                while (N % i == 0) {
                    N /= i;
                }
            }
        }
    
        // If N is still greater than 1, it must be prime
        if (N > 1) {
            primeFactors.push_back(N);
        }
    
        return primeFactors;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	
cout << "~" << "\n";
}  
	return 0;
}
// } Driver Code Ends