/*
class Node {
public:
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
      int ans = INT_MIN;
   int fun(Node* root){
       if(!root) return 0;
       
       int left = max(0,fun(root->left));
       int right = max(0,fun(root->right));
       
       ans = max(ans,left+right+root->data);
       
       return root->data + max(left,right);
   }
    // Function to return maximum path sum from any node in a tree.
    int findMaxSum(Node *root) {
        // code here
        fun(root);
        return ans;
    }
};