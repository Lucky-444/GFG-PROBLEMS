/*

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

*/

class Solution {
  public:
    bool ans = true;
    int solve(Node *root){
        if(!root){
            return 0;
        }
        
        if(!root -> left && !root -> right){
            return root -> data;
        }
        
        int leftSum  =  solve(root -> left);
        int rightSum = solve(root -> right);
        
        int totalSum = leftSum + rightSum;
        
        if(root -> data != totalSum){
           ans = false;
        }
        
        return  root -> data ;
    }
    int isSumProperty(Node *root) {
        // code here
        solve(root);
        
        return ans;
    }
};