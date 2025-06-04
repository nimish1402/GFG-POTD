/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(root, temp, ans);
        return ans;
    }
    
    void helper(Node* root, vector<int>& temp, vector<vector<int>>& ans){
        if(!root) return;
        
        temp.push_back(root->data);
        
        if(!root->left && !root->right){
            ans.push_back(temp);
        }
        else{
            helper(root-> left, temp, ans);
            helper(root ->right, temp, ans);
        }
        
        temp.pop_back();
    }
};