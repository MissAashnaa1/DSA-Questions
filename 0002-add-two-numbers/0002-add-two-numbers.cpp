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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1&&!l2){
            return NULL;
        }
        int sum=0;
        int carry=0;
    ListNode* dummy = new ListNode(-2);
    ListNode* dum = dummy;
        while(l1&&l2){
            sum=l1->val+l2->val+carry;
            carry=sum/10;
            sum=sum%10;
    ListNode* node = new ListNode(sum);

            dummy->next=node;
            dummy=dummy->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1){
            sum= l1->val+carry;
            carry=sum/10;
            sum=sum%10;
             ListNode* node = new ListNode(sum);
            dummy->next=node;
            dummy=dummy->next;
            l1=l1->next;
        }
        while(l2){
            sum= l2->val+carry;
            carry=sum/10;
            sum=sum%10;
             ListNode* node = new ListNode(sum);
            dummy->next=node;
            dummy=dummy->next;
            l2=l2->next;
        }
        if(carry){
            ListNode* node = new ListNode(carry);
            dummy->next=node;
            dummy=dummy->next;
        }
        dummy->next=NULL;
        return dum->next;
    }
};