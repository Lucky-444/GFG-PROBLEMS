/* Binary Tree Node Structure
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
public:
    vector<int> v;

    void dfs(Node* root, int level) {
        if(root == NULL) return;

        if(root->left == NULL && root->right == NULL) {
            v.push_back(level);
            return;
        }

        dfs(root->left, level + 1);
        dfs(root->right, level + 1);
    }

    int getCount(Node* root, int k) {
        dfs(root, 1);

        sort(v.begin(), v.end());

        int ans = 0;

        for(auto x : v) {
            if(k >= x) {
                k -= x;
                ans++;
            } else {
                break;
            }
        }

        return ans;
    }
};