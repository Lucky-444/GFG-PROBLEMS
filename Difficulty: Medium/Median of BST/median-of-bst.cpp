/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int countNodes(Node* root) {
        if (!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
    void inorder(Node* root, int& count, int target1, int target2, double& val1, double& val2) {
        if (!root) return;

        inorder(root->left, count, target1, target2, val1, val2);

        count++;
        if (count == target1) val1 = root->data;
        if (count == target2) val2 = root->data;

        inorder(root->right, count, target1, target2, val1, val2);
    }
    int findMedian(Node* root) {
        // Code here
        int n = countNodes(root);
        int target1, target2;

        if (n % 2 == 0) { 
            target1 = n / 2; 
            target2 = n / 2; 
        } else { 
            target1 = target2 = (n + 1) / 2; 
        }
        
        int count = 0;
        double val1 = -1, val2 = -1;
        inorder(root, count, target1, target2, val1, val2);
        
        return val1;
        
    }
};