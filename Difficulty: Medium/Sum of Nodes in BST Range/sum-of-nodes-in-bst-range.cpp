/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void solve(Node *root , int low , int high , int &sum){
        if(!root){
            return ;
        }
        
        if(root -> data >= low && root -> data <= high){
            sum += root -> data ;
        }
        
        solve(root -> left , low, high , sum);
        solve(root -> right , low , high , sum);
    }
    int nodeSum(Node* root, int l, int r) {
        // code here
        int sum = 0;
        solve(root , l , r , sum);
        
        return sum;
    }
};
