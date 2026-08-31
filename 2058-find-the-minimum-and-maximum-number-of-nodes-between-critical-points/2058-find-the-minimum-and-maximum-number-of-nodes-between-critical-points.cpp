class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {

        vector<int> critical;

        int index = 1;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while (curr->next != NULL) {

            ListNode* next = curr->next;

            if ((curr->val > prev->val && curr->val > next->val) ||

              
                (curr->val < prev->val && curr->val < next->val)) {

                critical.push_back(index);
            }

            prev = curr;
            curr = next;
            index++;
        }

      
        if (critical.size() < 2) {
            return {-1, -1};
        }

        int minDist = INT_MAX;
        int maxDist = critical.back() - critical.front();

        for (int i = 1; i < critical.size(); i++) {
            minDist = min(minDist,
                          critical[i] - critical[i - 1]);
        }

        return {minDist, maxDist};
    }
};