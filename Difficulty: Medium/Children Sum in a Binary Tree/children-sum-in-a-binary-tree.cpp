/*Complete the function below

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){80
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    
    bool checksum(Node* root){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return true;
        }
        
        int leftdata = (root->left) ? root->left->data : 0;
        int rightdata = (root->right) ? root->right->data : 0;
        
        if(root->data == leftdata + rightdata 
            && checksum(root->left)
            && checksum(root->right)
            ){
                return true;
            }
        return false;
    }
    int isSumProperty(Node *root) {
        return checksum(root) ? 1 : 0; 
    }
};