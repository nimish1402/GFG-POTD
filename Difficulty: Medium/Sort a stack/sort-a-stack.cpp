//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);

cout << "~" << "\n";
}
}
// } Driver Code Ends


/*The structure of the class is
class SortedStack{
public:
	stack<int> s;
	void sort();

};
*/

/* The below method sorts the stack s 
you are required to complete the below method */
// Helper function to insert an element into the sorted stack

void SortedStack::sort() {
    // Base case: if the stack is empty or has only one element, it's already sorted
    if (s.empty() || s.size() == 1) {
        return;
    }

    // Step 1: Remove the top element
    int topElement = s.top();
    s.pop();

    // Step 2: Recursively sort the remaining stack
    sort();

    // Step 3: Insert the removed element back in the sorted stack
    // Logic to insert the element in the sorted order
    stack<int> tempStack;
    while (!s.empty() && s.top() > topElement) {
        tempStack.push(s.top());
        s.pop();
    }

    // Push the current element into the stack
    s.push(topElement);

    // Move back elements from tempStack
    while (!tempStack.empty()) {
        s.push(tempStack.top());
        tempStack.pop();
    }
}


