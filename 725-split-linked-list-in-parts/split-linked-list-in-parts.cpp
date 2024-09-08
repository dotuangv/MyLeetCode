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
    int Count(ListNode *head)
    {
        if(head == NULL) return 0;
        return 1 + Count(head->next);
    }

    // int Solve()

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int cnt = Count(head);
        vector<ListNode*> ans;
        int x = k;
        for(int i = 0; i < x; i++)
        {
            ListNode* res = head;
            int t = cnt/k + (cnt % k != 0);
            for(int j = 0; j < t - 1; j++)
            {
                head = head->next;
            }
            if(head != NULL)
            {
                ListNode *tmp = head->next;
                head->next = NULL;
                head = tmp;
            }
            k--;
            cnt -= t;
            ans.push_back(res);
        }
        return ans;
    }
};