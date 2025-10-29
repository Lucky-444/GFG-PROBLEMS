/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    void mirror(Node* node) {
          // Base case: If the current node is null, do nothing
        if (node == nullptr) {
            return;
        }
        
        // Swap the left and right child pointers
        Node* temp = node -> left;
        node -> left = node -> right;
        node -> right = temp;
        
        // Recur for left and right subtrees
        mirror(node -> left);
        mirror(node -> right);
    }
};