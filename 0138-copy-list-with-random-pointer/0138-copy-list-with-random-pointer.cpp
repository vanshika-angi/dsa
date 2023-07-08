/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
       //1. create duplicate node after each node

       if(head==NULL)return NULL;

       Node* itr = head;
        Node* coming = NULL;
       while(itr!=NULL)
       {
           coming = itr->next;
           Node* copy = new Node(itr->val);
           copy->next=coming;
           itr->next=copy;
           itr=coming;
       } 

       //2.to assign random pointers of copies

       itr=head;
       while(itr!=NULL)
       {
           if(itr->random!=NULL)
           {
               itr->next->random = itr->random->next;
               
           }
           itr= itr->next->next;
       }


       //3. get duplicate linked list and restor original;
       itr=head;
       Node* copy=head;
       Node*pseudohead = NULL;


       while(itr!=NULL)
       {
           coming=itr->next->next;
           copy=itr->next;
           if(pseudohead==NULL)pseudohead=copy;
           itr->next=coming;
           if(coming!=NULL)copy->next=coming->next;
           itr=coming;

       }

       return pseudohead;
    }
};