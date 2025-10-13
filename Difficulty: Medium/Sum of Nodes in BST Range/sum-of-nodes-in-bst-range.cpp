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
      void solve(Node* root, int l, int h, int & sum){
        if(!root) return;
        
        if(root->data>=l && root->data<=h ) sum += root->data;
        
        solve(root->left,l,h,sum);
        solve(root->right,l,h,sum);
    }
    int nodeSum(Node* root, int low, int high) {
        // code here
         int sum = 0;
        solve(root, low, high, sum);
        return sum;
    }
};
