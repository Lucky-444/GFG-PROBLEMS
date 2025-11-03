/*The Node is defined as follows:
struct Node
{
    int data ;
    struct Node * left, * right ;
};
*/

class Solution {
  public:
    /*You are required to complete below method */
    vector<int> ans;

    int solve(Node* root, int k) {
        if (!root) return 0;

        // Leaf node
        if (!root->left && !root->right) {
            return 1;
        }

        int left = solve(root->left, k);
        int right = solve(root->right, k);

        int totalLeaves = left + right;

        if (totalLeaves == k) {
            ans.push_back(root->data);
        }

        return totalLeaves;
    }

    vector<int> btWithKleaves(Node *ptr, int k) {
        ans.clear();
        solve(ptr, k);
        if (ans.empty()) return {-1};
        return ans;
    }
};