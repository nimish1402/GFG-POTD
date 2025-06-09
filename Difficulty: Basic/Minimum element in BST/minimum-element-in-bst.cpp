// Function to find the minimum element in the given BST.

/* struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}
*/

class Solution {
  public:
    int minValue(Node* root) {
        
        int min = INT_MAX;
        
        while(root != NULL){
            min = root->data;
            root = root->left;    
        }
        
        return min;
    }
};