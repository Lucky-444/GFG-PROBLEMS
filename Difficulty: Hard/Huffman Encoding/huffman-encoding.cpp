class Solution {
  public:
  
    struct Node {
        int freq;
        int idx;
        Node* left;
        Node* right;
        
        Node(int f, int i) {
            freq = f;
            idx = i;
            left = right = NULL;
        }
    };
    
    struct cmp {
        bool operator()(Node* a, Node* b) {
            if (a->freq == b->freq)
                return a->idx > b->idx; // tie-breaking
            return a->freq > b->freq;   // min heap
        }
    };
    
    // preorder traversal
    void dfs(Node* root, string code, vector<string> &ans) {
        if (!root) return;

        // leaf node
        if (!root->left && !root->right) {
            ans.push_back(code);
            return;
        }

        dfs(root->left, code + "0", ans);
        dfs(root->right, code + "1", ans);
    }
    
    vector<string> huffmanCodes(string &s, vector<int> f) {
        int n = s.size();
        
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        // push all nodes
        for (int i = 0; i < n; i++) {
            pq.push(new Node(f[i], i));
        }
        
        // build Huffman tree
        while (pq.size() > 1) {
            Node* left = pq.top(); pq.pop();
            Node* right = pq.top(); pq.pop();
            
            Node* parent = new Node(left->freq + right->freq, min(left->idx, right->idx));
            parent->left = left;
            parent->right = right;
            
            pq.push(parent);
        }
        
        Node* root = pq.top();
        
        vector<string> ans;
        
        // edge case
        if (n == 1) {
            ans.push_back("0");
            return ans;
        }
        
        // preorder traversal to collect codes
        dfs(root, "", ans);
        
        return ans;
    }
};