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
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>>ans;
        
        map<int , vector<int>>mp;
        
        queue<tuple<Node* , int>>q;
        q.push({root , 0});
        
        while(!q.empty()){
            auto [node , col] = q.front();
            q.pop();
            
            mp[col].push_back(node -> data);
            
            if(node -> left){
                q.push({node -> left , col - 1});
            }
            
            if(node -> right){
                q.push({node -> right , col + 1});
            }
        }
        
        
        for(auto [col , vec] : mp){
            ans.push_back(vec);
        }
        
        return ans;
        
    }
};