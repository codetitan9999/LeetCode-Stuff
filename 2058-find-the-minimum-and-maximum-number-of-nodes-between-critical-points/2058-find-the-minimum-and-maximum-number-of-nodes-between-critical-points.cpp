class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
      
        if (!head || !head->next || !head->next->next)
            return {-1, -1};

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        int firstCritical = -1;
        int prevCritical = -1;

        int minDistance = INT_MAX;
        int maxDistance = -1;

        while (curr->next) {
            ListNode* next = curr->next;


            bool isCritical =
                (curr->val > prev->val && curr->val > next->val) ||
                (curr->val < prev->val && curr->val < next->val);

            if (isCritical) {
                if (firstCritical == -1) {

                    firstCritical = index;
                } 
                else {
                    minDistance = min(
                        minDistance,
                        index - prevCritical
                    );


                    maxDistance = index - firstCritical;
                }

                prevCritical = index;
            }

            prev = curr;
            curr = next;
            index++;
        }

        if (maxDistance == -1)
            return {-1, -1};

        return {minDistance, maxDistance};
    }
};