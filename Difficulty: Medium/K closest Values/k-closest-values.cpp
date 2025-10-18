/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    void inorder(Node* root, vector<int>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root->data);
        inorder(root->right, nodes);
    }

    vector<int> getKClosest(Node* root, int target, int k) {
        // code here
    vector<int> nodes;
    inorder(root, nodes); // Step 1: store all BST values (sorted)

    // Step 2: sort by closeness (and value if tie)
    sort(nodes.begin(), nodes.end(), [&](int a, int b) {
        double diffA = fabs(a - target);
        double diffB = fabs(b - target);
        if (diffA == diffB) return a < b; // tie → smaller one
        return diffA < diffB;
    });

    // Step 3: take first k values
    vector<int> ans;
    for (int i = 0; i < k && i < nodes.size(); i++) {
        ans.push_back(nodes[i]);
    }
    return ans;  
    }
};