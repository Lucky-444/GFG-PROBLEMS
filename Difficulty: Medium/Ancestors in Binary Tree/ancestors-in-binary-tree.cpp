/*
Structure of a node is as following
struct Node
{
     int data;
     struct Node* left;
     struct Node* right;
};
*/

class Solution {
  public:
    //mark parent Method
    unordered_map<Node * , Node*>parent;
    Node*  markParent(Node * root , int target){
        Node* startNode = NULL ;
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            
            if(node -> data == target){
                startNode = node;
            }
            
            if(node -> left){
                parent[node -> left] = node;
                q.push(node -> left);
            }
            
            if(node -> right){
                parent[node -> right] = node; 
                q.push(node -> right);
            }
        }
        
        return startNode ;
    }
    // Function should return all the ancestor of the target node
    vector<int> Ancestors(struct Node *root, int target) {
        // Code here
        
        Node *start = markParent(root , target);
        
        vector<int>ans;
        
        while(parent.count(start)){
            ans.push_back(parent[start] -> data);
            start = parent[start];
        }
        
        return ans;
    }
};