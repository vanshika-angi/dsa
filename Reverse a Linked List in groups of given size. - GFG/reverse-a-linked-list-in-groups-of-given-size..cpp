//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


struct node
{
    int data;
    struct node* next;
    
    node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print linked list */
void printList(struct node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}


// } Driver Code Ends
/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
    struct node
    {
        int data;
        struct node* next;
    
        node(int x){
            data = x;
            next = NULL;
        }
    
    }*head;
*/

class Solution
{
    public:
    
    struct node *reverse (struct node *head, int k)
    { 
        
        if(head==NULL)return NULL;
        if(k==1)return head;
        node* temp=head;
        node* HEAD=NULL;
        
        node*Next=NULL;
        node*curr_head=temp;
        node*prev_head=temp;
        
        while(temp!=NULL)
        {
            node*prev=NULL;
            curr_head=temp;
            int count=k;
            while(temp!=NULL && count>0)
            {
                Next=temp->next;
                temp->next=prev;
                prev=temp;
                temp=Next;
                // cout<<prev->data<<endl;
                count--;
            }
            if(HEAD==NULL)
            {
                HEAD=prev;
            }
            if(curr_head!=head)
            {
                prev_head->next=prev;
                prev_head=curr_head;
            }
        
        }
        return HEAD;
    }
};


//{ Driver Code Starts.

/* Drier program to test above function*/
int main(void)
{
    int t;
    cin>>t;
     
    while(t--)
    {
        struct node* head = NULL;
        struct node* temp = NULL;
        int n;
        cin >> n;
         
        for(int i=0 ; i<n ; i++)
        {
            int value;
            cin >> value;
            if(i == 0)
            {
                head = new node(value);
                temp = head;
            }
            else
            {
                temp->next = new node(value);
                temp = temp->next;
            }
        }
        
        int k;
        cin>>k;
        
        Solution ob;
        head = ob.reverse(head, k);
        printList(head);
    }
     
    return(0);
}


// } Driver Code Ends