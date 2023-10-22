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
    ListNode* rotateRight(ListNode* head, int k) {
    if (!head || !head->next) {
        return head;
    }
    
    int n = 1; // Initialize n to 1
    ListNode* node = head;
    
    // Count the number of elements in the linked list
    while (node->next) {
        n++;
        node = node->next;
    }
    
    k = k % n; // Correct the value of k
    
    if (k == 0) {
        return head;
    }
    
    // Find the new head and the node just before NULL
    node = head;
    for (int i = 0; i < n - k - 1; i++) {
        node = node->next;
    }
    
    ListNode* beforeNull = node;
    ListNode* returnHead = node->next;
    
    // Connect the end to the original head
    node = returnHead;
    while (node->next) {
        node = node->next;
    }
    
    node->next = head;
    beforeNull->next = NULL;
    
    return returnHead;
}
};