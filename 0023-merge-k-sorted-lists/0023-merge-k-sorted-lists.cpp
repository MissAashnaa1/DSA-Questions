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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(-1);
        priority_queue<ListNode*, vector<ListNode*>, function<bool(ListNode*, ListNode*)>> pq([](ListNode *a, ListNode *b) {
    return a->val > b->val;
});
        
        ListNode* curr=dummy;
        for(auto Hnode : lists){
            if(Hnode!=NULL)
            pq.push(Hnode);
        }

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();
            
            curr->next = node;
            curr = node;

            if (node->next != NULL) {
                pq.push(node->next);
            }
        }
        curr->next = NULL;
        return dummy->next;
    }
};