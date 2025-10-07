/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    map<int,int>mp;
    vector<int> bottomView(Node *root) {
        // code here
        if(!root) return {}; 
        
        queue<pair<Node*,int>>q;
        q.push({root,0});
        
        while(!q.empty()){
           auto it=q.front();
           Node *temp=it.first;
           int line=it.second;
            q.pop();
            
            
                mp[line]=temp->data;
            
            
            if(temp->left){
                q.push({temp->left,line-1});
                
            }
            if(temp->right){
                q.push({temp->right,line+1});
            }
            
        }
        
        vector<int>ans;
        for(auto it:mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};