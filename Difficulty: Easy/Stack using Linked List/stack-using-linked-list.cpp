//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode *next;

    StackNode(int a) {
        data = a;
        next = NULL;
    }
};


// } Driver Code Ends
class MyStack {
  private:
    StackNode *top;

  public:
    void push(int x) {
        StackNode* newnode = new StackNode(x);
        newnode->next = top;
        top = newnode;
    }

    int pop() {
        if (top == nullptr) {
            return -1;  // If the stack is empty, return -1
        }
        int poppedValue = top->data;  // Get the value of the top node
        StackNode* temp = top;             // Temporary pointer to the top node
        top = top->next;              // Move the top pointer to the next node
        delete temp;                  // Delete the old top node
        return poppedValue;
    }

    MyStack() { top = NULL; }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        MyStack *sq = new MyStack();
        string line;
        getline(cin, line);
        stringstream ss(line);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        int n = nums.size();
        int i = 0;
        while (i < n) {
            int QueryType = nums[i++];
            if (QueryType == 1) {
                int a = nums[i++];
                sq->push(a);
            } else if (QueryType == 2) {
                cout << sq->pop() << " ";
            }
        }
        cout << endl;
        cout << "~"
             << "\n";
        delete sq;
    }
}

// } Driver Code Ends