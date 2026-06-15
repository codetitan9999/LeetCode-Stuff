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
    ListNode* mp(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode * slow = head;
        ListNode* fast = head->next->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode* deleteMiddle(ListNode* head) {
        if(!head ||!head->next) return NULL;
        ListNode* prev = mp(head);
        prev ->next = prev->next->next;
        return head;
        
    }
};