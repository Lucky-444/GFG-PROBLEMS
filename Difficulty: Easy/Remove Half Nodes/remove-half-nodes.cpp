/* 
 * Definition for a binary tree node:
 * Each node contains:
 *   - int data (value of node)
 *   - Node* left (pointer to left child)
 *   - Node* right (pointer to right child)
 */

/*
 * Goal:
 * Remove all "half nodes" (nodes with exactly one child)
 * and return the root of the modified tree.
 */

class Solution {
  public:
  
    // Recursive helper function to remove half nodes
    Node* solve(Node* root) {
        // BASE CASE 1: If the current node is NULL → return NULL
        if (!root) {
            return NULL;
        }

        // STEP 1: Recurse for left and right subtrees first
        // We first clean the child subtrees before making decisions about the parent.
        root->left = solve(root->left);
        root->right = solve(root->right);

        // STEP 2: Check if this node is a half node (only one child)
        
        // Case A: No left child but has a right child → remove current node
        if (!root->left && root->right) {
            Node* temp = root->right;  // Save right child
            delete root;               // Delete current node (free memory)
            return temp;               // Return the right child to parent
        }

        // Case B: No right child but has a left child → remove current node
        if (!root->right && root->left) {
            Node* temp = root->left;   // Save left child
            delete root;               // Delete current node (free memory)
            return temp;               // Return the left child to parent
        }

        // STEP 3: If node has both children or is a leaf node, keep it as it is
        return root;
    }

    // Main function to be called
    Node* RemoveHalfNodes(Node* root) {
        /*
         * We start the recursion from the root.
         * The function 'solve' will handle all removals recursively.
         */
        return solve(root);
    }
};
