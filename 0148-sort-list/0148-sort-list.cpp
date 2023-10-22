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
    ListNode* findMiddle(ListNode* head){
        ListNode* slow=head;
        ListNode* fast=head;
        ListNode* temp=head;
        while(fast&&fast->next){
            temp=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return temp;
    }
    ListNode* mergeList(ListNode* l1,ListNode* l2){
        ListNode* node1=l1;
        ListNode* node2=l2;
        ListNode* dummy=new ListNode(-1);
        ListNode* head=dummy;
        while(node1&&node2){
            if(node1->val<node2->val){
                dummy->next=node1;
                node1=node1->next;
            }
            else{
                dummy->next=node2;
                node2=node2->next;
            }
            dummy=dummy->next;
        }
        if(node1){
            dummy->next=node1;
            
        }
        if(node2){
            dummy->next=node2;
            
        }
        
        return head->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head||!head->next){
            return head;
        }
        ListNode* beforeMiddle=findMiddle(head);
        ListNode* head2=beforeMiddle->next;
        beforeMiddle->next=NULL;
       head= sortList( head);
       head2=sortList(head2);
        return mergeList(head,head2);
    }
};