/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int dia = 0 ;
    int solve(Node *root){
        if(!root){
            return 0 ;
        }
        
        int lh = solve(root -> left);
        int rh = solve(root -> right);
        
        dia = max(dia , (lh + rh)) ; 
        //take diametre is left subtree height + right Subtre height
        return max(lh , rh) + 1;
    }
    int diameter(Node* root) {
        // code here
        solve(root);
        return dia;
    }
};