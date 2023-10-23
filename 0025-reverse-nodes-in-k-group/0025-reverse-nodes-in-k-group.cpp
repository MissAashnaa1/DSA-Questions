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
    ListNode* reverse(ListNode* head) {
        
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* newHead=reverse(head->next);
        ListNode* headNext=head->next;
        headNext->next=head;
        head->next=NULL;
        return newHead;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* node= head;
        int count=0;
        ListNode* dummy = new ListNode(-1);
        head=dummy;
        ListNode* temp=node;
        while(node){
            temp=node;
            while(++count<k&&temp->next){
                temp=temp->next;

            }
            if(count<k||temp==NULL){
                dummy->next=node;
                break;
            }
           
            ListNode* nex=temp->next;
            
            temp->next=NULL;
            
            
            
            dummy->next=reverse(node);
            while(dummy->next){
                 dummy=dummy->next;
            }
            // dummy=node;
            node=nex;
            count=0;

        }
        return head->next;

    }
    
};