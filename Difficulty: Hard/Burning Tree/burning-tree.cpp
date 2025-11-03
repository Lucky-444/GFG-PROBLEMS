/*
class Node {
  public:
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
    unordered_map<Node*, Node*> parent;
    void inorder(Node* root) {
        if (!root)
            return;

        if (root->left) {
            parent[root->left] = root;
        }
        inorder(root->left);

        if (root->right) {
            parent[root->right] = root;
        }
        inorder(root->right);
    }
    
     Node* find(Node* root, int target) {
        if (root == NULL) return NULL; 
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* temp = q.front(); 
            q.pop();
            if (temp->data == target) {
                return temp;
            }

            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
        return NULL;
    }
    
    int minTime(Node* root, int target) 
    {
        unordered_map<Node*,bool>vis;
        
        inorder(root);
        
        Node* targetNode = find(root, target);
        
        queue<Node*>q;
        q.push(targetNode);
        
         if (!targetNode) return 0;  
         
         vis[targetNode]=true;
         int Time=0;
         
         
         while(!q.empty()){
             
             int size=q.size();

            for(int i=0;i<size;i++){
                Node * temp=q.front();
                q.pop();
                
                if(temp->left && !vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left]=true;
                }
                
                if(temp->right && !vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right]=true;
                }
                
                if(parent[temp] && !vis[parent[temp]]){
                    q.push(parent[temp]);
                    vis[parent[temp]]=true;
                }
            }
            
             Time+=1;
             //cout<<Time<<endl;
         }
         
         return Time-1;
    
    }
};