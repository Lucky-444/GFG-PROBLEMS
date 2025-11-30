
#include <iostream> 
#include<vector>
using namespace std; 

class TrieNode 
{ 
    public:
    
    // Stores binary representation 
    // of numbers 
    TrieNode *child[2]; 

    // Stores count of elements 
    // present in a node 
    int cnt; 
    TrieNode() { 
        child[0] = child[1] = NULL; 
        cnt = 0; 
    } 
}; 


// Function to insert a number into Trie 
void insertTrie(TrieNode *root, int n) { 
    
    // Traverse binary representation of x 
    for (int i = 31; i >= 0; i--) { 
        
        // Stores ith bit of n 
        bool x = (n) & (1 << i); 
        
        // Check if an element already 
        // present in Trie having ith bit x
        if(!root->child[x]) { 
            root->child[x] = new TrieNode(); 
        } 
        
        // Update count of elements 
        // whose ith bit is x 
        root->child[x]->cnt+= 1; 
        
        // Update root 
        root= root->child[x]; 
    } 
} 


// Function to count elements 
// in Trie whose XOR with n 
// less than k
int cntSmaller(TrieNode * root, 
                int n, int k) 
{
    int cntPairs = 0; 
    
    // Traverse binary representation 
    // of n and k in Trie 
    for (int i = 31; i >= 0 && 
                    root; i--) { 
                                    
        // Stores ith bit of n                         
        bool x = n & (1 << i); 
        
        // Stores ith bit of k
        bool y = k & (1 << i); 
        
        // If the ith bit of k is 1 
        if (y) { 
            
            // If an element already 
            // present in Trie having 
            // ith bit (x)
            if(root->child[x]) {
                    cntPairs  +=
                    root->child[x]->cnt; 
            }
        
            root = 
                root->child[1 - x]; 
        } 
        
        // If the ith bit of k is 0 
        else{ 
            
            // Update root 
            root = root->child[x]; 
        } 
    } 
    return cntPairs; 
} 

class Solution {
  public:
    int cntPairs(vector<int>& arr, int k) {
        
        TrieNode *root = new TrieNode();
        int ans = 0;
        
        // Insert elements one by one and count pairs
        for(int i = 0; i < arr.size(); i++) {
            
            // For every element already in Trie, count how many
            // numbers have XOR < k with arr[i]
            ans += cntSmaller(root, arr[i], k);
            
            // Insert current number into Trie
            insertTrie(root, arr[i]);
        }
        
        return ans;
    }
};
