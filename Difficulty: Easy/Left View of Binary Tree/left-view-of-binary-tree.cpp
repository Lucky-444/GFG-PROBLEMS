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
    vector<int> leftView(Node *root) {
        // code here
        //the first node from left side
        
        vector<int>ans;
        
        queue<Node *>q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            
            int val = -1;
            while(n --){
                auto node = q.front();
                q.pop();
                
                if(val == -1){
                    val = node -> data;
                }
                
                if(node -> left){
                    q.push(node -> left);
                }
                
                if(node -> right){
                    q.push(node -> right);
                }
            }
            
            ans.push_back(val);
        }
        
        return ans;
    }
};