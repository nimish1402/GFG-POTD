//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insertAtBottom(stack<int>& St, int element) {
        // Base case: If the stack is empty, push the element directly
        if (St.empty()) {
            St.push(element);
            return;
        }

        // Step 1: Remove the top element
        int topElement = St.top();
        St.pop();

        // Step 2: Recursively insert the element at the bottom
        insertAtBottom(St, element);

        // Step 3: Push the top element back
        St.push(topElement);
    }

    // Function to reverse the stack
    void Reverse(stack<int>& St) {
        // Base case: If the stack is empty or has only one element, it's already reversed
        if (St.empty() || St.size() == 1) {
            return;
        }

        // Step 1: Remove the top element
        int topElement = St.top();
        St.pop();

        // Step 2: Recursively reverse the remaining stack
        Reverse(St);

        // Step 3: Insert the removed element at the bottom of the stack
        insertAtBottom(St, topElement);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    
cout << "~" << "\n";
}
}
// } Driver Code Ends