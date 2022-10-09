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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        ListNode * temp=head;
        while(temp!=NULL) {
            arr.push_back(temp->val);
            temp=temp->next;
        }
        stack<int> s;
        vector<int> ans(arr.size());
        for(int i=arr.size()-1;i>=0;i--) {
            while(s.empty()!=true && arr[i]>=s.top())
                s.pop();
            if(s.empty())
                ans[i]=0;
            else
                ans[i]=s.top();
            s.push(arr[i]);
        }
        return ans;
    }
};