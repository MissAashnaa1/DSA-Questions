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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node=head;
        
        while(n--){
            node=node->next;
        }
        
        ListNode* temp=head;
        if(node==NULL){
            return temp->next;
        
        }
        while(node->next!=NULL){
            temp=temp->next;
            node=node->next;
        }
        // if(temp==NULL){
        //     return head;
        // }
        ListNode* del=temp->next;

    temp->next=del->next;
    delete del;
    return head;
    }
    
};