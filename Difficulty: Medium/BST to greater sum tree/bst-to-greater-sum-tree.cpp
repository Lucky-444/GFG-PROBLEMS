/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};*/

class Solution {
    public : 
    int i=0;
    void inorder(Node* root,vector<int>&val){
        if(!root) return;
        inorder(root->left,val);
        val.push_back(root->data);
        inorder(root->right,val);
        return;
    }
    void updateBST(Node* root,vector<int>&val){
        if(!root) return;
        updateBST(root->left,val);
        root->data = val[i++];
        updateBST(root->right,val);
        return;
    }
    void transformTree(Node *root) {
        // code here
        vector<int>val;
        inorder(root,val);
        int n = val.size();
        int sum = 0;
        for(int j=n-1;j>=0;j--){
            int temp = val[j];
            val[j] = sum;
            sum += temp;
        }
        updateBST(root,val);
    }
};