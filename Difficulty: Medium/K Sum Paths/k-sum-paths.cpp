// User function template for C++

/*
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
  int cnt = 0;
    unordered_map<long long, int> mp;
    void dfs(Node* root, long long prefix_sum, int target) {
        if (!root)
            return;

        prefix_sum += root->data;
        if (mp.find(prefix_sum - target) != mp.end()) {
            cnt += mp[prefix_sum - target];
        }

        mp[prefix_sum]++;
        dfs(root->left, prefix_sum, target);
        dfs(root->right, prefix_sum, target);

        mp[prefix_sum]--;
    }
    int pathSum(Node* root, int targetSum) {
        mp[0] = 1;

        dfs(root, 0L, targetSum);

        return cnt;
    }
    int countAllPaths(Node *root, int k) {
        // code here
       return pathSum(root,k);
    }
};

