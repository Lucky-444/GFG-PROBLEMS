/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
 int ans = -1;
    void fun(Node* root,int &k){
        if(!root) return;
        
        fun(root->left,k);
        
        if(--k == 0){
            ans = root->data;
        }
        
        fun(root->right,k);
        
        
    }
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        // add code here.
        fun(root,k);
        return ans;
        
    }
};