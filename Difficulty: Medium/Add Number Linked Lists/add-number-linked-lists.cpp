/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node * reverse(Node *num){
        Node *curr = num ; 
        Node *prev = NULL ; 
        Node *next = NULL ; 
        
        while(curr){
            next = curr -> next ;
            curr -> next = prev ;
            prev = curr ; 
            curr = next ; 
        }
        
        return prev;
    }
    Node* addTwoLists(Node* head1, Node* head2) {
        // code here
        Node *n1 = reverse(head1);
        Node *n2 = reverse(head2);
        
        Node *ans = new Node(0);
        Node *curr = ans;
        
        
        int carry = 0 ;
        while(n1 || n2 || carry){
            int sum = carry ; 
            
            if(n1){
                sum += n1 -> data; 
                n1  = n1 -> next ;
            }
            
            if(n2){
                sum += n2 -> data; 
                n2 = n2 -> next ; 
            }
            
            ans -> data = sum % 10 ; 
            carry = sum / 10 ;
            
            if(n1 || n2 || carry){
                ans -> next = new Node(0);
                ans = ans -> next; 
            }
        }
        
        // now curr points to starting of ans
        //reverse the curr pointer
        reverse(curr);
        
        while(ans -> data == 0 && ans -> next){
            ans = ans -> next ;
        }
        
        return ans; 
    }
};