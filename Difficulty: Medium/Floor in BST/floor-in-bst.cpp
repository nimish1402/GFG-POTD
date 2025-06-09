// Function to search a node in BST.
class Solution {

  public:
    int floor(Node* root, int x) {
        // Code here
        int flor = -1;
        
        while(root){
            
            if(root->data == x){
                flor = root->data;
                return flor;
            }
            if(x > root->data){
                
                flor = root->data;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return flor;
    }
};