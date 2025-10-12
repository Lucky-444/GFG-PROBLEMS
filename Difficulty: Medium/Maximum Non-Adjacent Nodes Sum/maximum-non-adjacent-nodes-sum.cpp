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
  map<Node* ,int > dp;
   int sum(Node*root){
       if(!root) return 0;
       // ..pick and not_pick condition
       int inc = root->data;
       
       if(dp[root]){
          return dp[root]; 
       }
        
        if(root->left){
            inc+=sum(root->left->left)+ sum(root->left->right);
        }
        
        if(root->right){
            inc+=sum(root->right->left) + sum(root->right->right);
        }
        
        int exc = sum(root->left) + sum(root->right);
        
        return dp[root] = max(inc,exc);
   }
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        // Add your code here
        //convert it to a dp problem best of dp
        
        return sum(root);
       
        
    }
};