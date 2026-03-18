/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class box{
     public:
     int size;
     int min,max;
     bool bst;
     box(){
         size=0;
         min=INT_MAX;
         max=INT_MIN;
         bst=true;
     }
 };
class Solution{
    public:
    box *find(Node *root,int &x){
        //if root not exist
        if(!root){
            return new box();
        }
        
        
        //if root exist;
        box* lefthead=find(root->left,x);
        box * righthead=find(root->right,x);
        
        if(lefthead->bst && righthead->bst && lefthead->max < root->data && righthead->min > root->data){
            box* head=new box();
            head->size=lefthead->size + righthead->size + 1;
            head->min=min(root->data,lefthead->min);
            head->max=max(root->data,righthead->max);
            x=max(x,head->size);
            return head;
        }
        else{
            lefthead->bst=0;
            return lefthead;
        }
    }
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
    	//Your code here
    	int t=0;
    	find(root , t);
    	return t;
    	
    }
};