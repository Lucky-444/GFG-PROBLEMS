
/* BST Node
class Node
{
   public:
    int data;
    Node *left;
    Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
   public:
    Node* pre = nullptr;
    Node* suc = nullptr;
    
    void findsuccessor(Node* root, int k) {
        Node* curr = root;
        while (curr != NULL) {
            if (k < curr->data) {
                suc = curr;
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
    }

    void findpredecessor(Node* root, int k) {
        Node* curr = root;
        while (curr != NULL) {
            if (k > curr->data) {
                pre = curr;
                curr = curr->right;
            } else {
                curr = curr->left;
            }
        }
    }

    vector<Node*> findPreSuc(Node* root, int key) {
        pre = nullptr;
        suc = nullptr;
        findpredecessor(root, key);
        findsuccessor(root, key);
        return {pre, suc};
    }


};

