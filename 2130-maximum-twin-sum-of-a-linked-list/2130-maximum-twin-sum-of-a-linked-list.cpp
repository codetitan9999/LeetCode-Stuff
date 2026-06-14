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
        ListNode * fast = head->next->next;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode * rev(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    int pairSum(ListNode* head) {
        if(!head || !head->next) return 0;
        ListNode * m = mp(head);
        ListNode* head2 = m->next;
        ListNode* p1 = head;
        m->next = NULL;
        ListNode* p2 = rev(head2);
        int ans = 0;
        while(p1 && p2) {
            ans = max(ans , p1->val + p2->val);
            p1 = p1->next;
            p2 = p2->next;
        }
        return ans;
    }
};