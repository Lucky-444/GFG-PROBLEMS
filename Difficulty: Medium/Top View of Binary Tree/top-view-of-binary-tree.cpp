/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> topView(Node *root) {
        // code here
        //top side vi
        map<int ,int>mp;
        
        queue<pair<Node * , int>>q;
        
        q.push({root , 0});
        
        while(!q.empty()){
            auto [node , line] = q.front();
            q.pop();
            
            if(mp.find(line) == mp.end()){
                mp[line] = node -> data;
            }
            
            if(node -> left){
                q.push({node -> left , line - 1});
            }
            
            if(node -> right){
                q.push({node -> right , line + 1});
            }
        }
        
        
        vector<int>ans;
        for(auto [line, val] : mp){
            ans.push_back(val);
        }
        
        return ans;
    }
};