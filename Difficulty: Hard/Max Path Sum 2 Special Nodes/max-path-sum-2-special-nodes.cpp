class Solution {
public:
    int maxSum = INT_MIN;

    int solve(Node* root) {
        if (!root) return 0;

        // If it's a leaf node (special node)
        if (!root->left && !root->right)
            return root->data;

        // Recur for left and right subtrees
        int left = (root->left) ? solve(root->left) : INT_MIN;
        int right = (root->right) ? solve(root->right) : INT_MIN;

        // If both children exist, we can form a path through this node
        if (root->left && root->right) {
            maxSum = max(maxSum, left + right + root->data);
            return root->data + max(left, right);
        }

        // If only one child exists, continue that path
        return root->data + (root->left ? left : right);
    }

    int maxPathSum(Node* root) {
        maxSum = INT_MIN;
        int val = solve(root);

        // If the tree has only one special node, handle edge case
        return maxSum == INT_MIN ? val : maxSum;
    }
};
