//User function Template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */


class Solution
{
public: 
   int solve(Node* root, int& ans, int& maxi) {
        if(root==NULL) return -1;
        
        int left = solve(root->left,ans,maxi);
        int right = solve(root->right,ans,maxi);
        
        int gcd = __gcd(left,right);
        if(left!=-1 && right!=-1 && gcd>maxi) {
            maxi = gcd;
            ans = root->data;
        }
        return root->data;
    }
    int maxGCD( Node* root)
    {
        if(root==NULL) return 0;
        int ans=0,maxi=0;
        solve(root,ans,maxi);
        return ans;
    }
};

