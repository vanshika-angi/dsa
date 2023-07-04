/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* Merge(ListNode* list1, ListNode* list2)
    {
         if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        
        ListNode* temp=new ListNode(-200);
        
        ListNode*HEAD=temp;
        
        while(list1!=NULL && list2!=NULL)
        {
            if(list1->val<=list2->val)
            {
                temp->next=list1;
                list1=list1->next;
                temp=temp->next;
            }
            else
            {
                temp->next=list2;
                list2=list2->next;
                temp=temp->next;
            }
        }
        
        if(list1!=NULL)temp->next=list1;
        else temp->next=list2;
        
        
        return HEAD->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)return NULL;
        ListNode* res = lists[0];
        
        for(int i=1;i<lists.size();i++)
        {
            res=Merge(res,lists[i]);
        }
        
        return res;
    }
};