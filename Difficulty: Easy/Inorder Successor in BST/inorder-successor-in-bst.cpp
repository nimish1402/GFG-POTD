/*The structure of Node

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    int inOrderSuccessor(Node *root, Node *x) {
       
       vector<int> result;
       inorderHelper(root, result);
       
       for(int i = 0; i < result.size(); i++){
           if(result[i] == x->data){
               if(i + 1 < result.size()){
                   return(result[i+1]);
               }
               else{
                   return -1;
               }
           }
       }
       return -1;
       
    }
    
    void inorderHelper(Node* root, vector<int>& result){
        if(root == nullptr) return;
        
        inorderHelper(root->left, result);
        result.push_back(root->data);
        inorderHelper(root->right, result);
    }
};