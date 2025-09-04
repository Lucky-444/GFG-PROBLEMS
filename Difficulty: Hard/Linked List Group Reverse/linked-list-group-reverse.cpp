/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
 Node* reverse(Node* head){
        if(head==NULL || head->next==NULL) return head;
        
        Node* curr = head;
        Node* prev = NULL;
        
        while(curr){
            Node* front = curr->next;
            curr->next=prev;
            prev=curr;
            curr=front;
        }
        return prev;
    }
    Node* findKthNode(Node* temp,int k){
        k--;
        while(temp!=NULL && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    Node *reverseKGroup(Node *head, int k) {
        // code here
        if(head==NULL || head->next==NULL) return head;
        Node* temp = head;
        Node* prevNode = NULL;
        while(temp){
            Node* kthNode = findKthNode(temp,k);
            if(kthNode == NULL){
                kthNode=temp;
                while(kthNode->next!=NULL){
                    kthNode=kthNode->next;
                }
            }
            Node* front = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if(temp==head){
                head=kthNode;
            }else{
                prevNode->next=kthNode;
            }
            prevNode=temp;
            temp=front;
        }
        return head;
    }
};