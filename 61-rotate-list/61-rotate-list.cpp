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
        if(head==NULL||head->next==NULL)
            return head;
        int len=1;
        ListNode * temp=head;
        while(temp->next!=NULL) {
            len++;
            temp=temp->next;
        }
        temp->next=head;
        k=k%len;
        temp=head;
        for(int i=1;i<len-k;i++) {
            temp=temp->next;
        }
        head=temp->next;
        temp->next=NULL;
        return head;
    }
};