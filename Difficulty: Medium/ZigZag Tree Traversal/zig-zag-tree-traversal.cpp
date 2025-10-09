/*
class Node {
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
    vector<int> zigZagTraversal(Node* root) {
        // code here
          vector<int>ans;
        vector<vector<int>>temp;
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty())
        {
            int size=q.size();
           vector<int>tt;
            for(int i=1;i<=size;i++)
            {
                Node*t=q.front();q.pop(); 
                tt.push_back(t->data);
                if(t->left!=NULL) q.push(t->left);
                if(t->right!=NULL) q.push(t->right);
                
                
            }
           
               
             temp.push_back(tt); 
            
        }
        for(int i=0;i<temp.size();i++)
        {
            if(i%2==0){
             for(int j=0;j<temp[i].size();j++)
            {
            ans.push_back(temp[i][j]);
            }
                
            }
            else
            {
             for(int j=temp[i].size()-1;j>=0;j--)
            {
            ans.push_back(temp[i][j]);
            }
                 
            }
        }
        return ans;
    }
};