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
    ListNode* merge(ListNode *l1,ListNode *l2){
        ListNode * current=new ListNode(0);
        ListNode * tail=current;

        while(l2!=nullptr && l1!=nullptr){
            if(l1->val<l2->val){
                tail->next=l1;
                l1=l1->next;
            }
            else{
                tail->next=l2;
                l2=l2->next;
            }
            tail=tail->next;
        }
        if(l1)tail->next=l1;
        if(l2)tail->next=l2;
        return current->next;


    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode * fast=head;
        ListNode * slow=head;
        ListNode * prev=NULL;

        while(fast && fast->next){
            prev=slow;

            slow=slow->next;
            fast=fast->next->next;

        }
        prev->next=NULL;

        ListNode *l1=sortList(head);
        ListNode *l2=sortList(slow);

        return merge(l1,l2);
        
    }
};