class Solution {
  public:
    bool isHeap(Node* root) {

        // Empty tree is a heap
        if (root == NULL) return true;

        queue<Node*> q;
        q.push(root);

        // This flag becomes true when a NULL child is seen
        bool seenNull = false;

        // Level order traversal
        while (!q.empty()) {
            Node* node = q.front();
            q.pop();

            // Check left child
            if (node->left) {

                // If a NULL child was seen before OR
                // heap property is violated
                if (seenNull || node->left->data > node->data) {
                    return false;
                }

                q.push(node->left);
            } 
            else {
                // Once a NULL child is found,
                // all following children must be NULL
                seenNull = true;
            }

            // Check right child
            if (node->right) {

                if (seenNull || node->right->data > node->data) {
                    return false;
                }

                q.push(node->right);
            } 
            else {
                seenNull = true;
            }
        }

        // Tree satisfies both CBT and max-heap property
        return true;
    }
};
