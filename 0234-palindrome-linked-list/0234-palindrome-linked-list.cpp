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
    ListNode* reverse(ListNode* head){
        if(!head||!head->next){
            return head;
        }
        ListNode* newHead=reverse(head->next);
        ListNode* headNext=head->next;
        headNext->next=head;
        head->next=NULL;
        return newHead;
    }
public:
    bool isPalindrome(ListNode* head) {
        if(!head||!head->next){
            return true;
        }
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast->next&&fast->next->next){
            fast=fast->next->next;
            slow=slow->next;

        }
        slow->next=reverse(slow->next);
        slow=slow->next;
        ListNode* dummy =head;
        while(slow!=NULL){
            if(slow->val!=dummy->val){
                return false;
            }
            slow=slow->next;
            dummy=dummy->next;
        }
        return true;
    }
};