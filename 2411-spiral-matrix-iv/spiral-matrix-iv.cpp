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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int> (n, -1));
        int l = 0, t = 0, r = n - 1, b = m - 1;
        while(head != NULL)
        {
            for(int i = l; i <= r; i++)
            {
                if(head == NULL) return ans;
                ans[t][i] = head->val;
                head = head->next;
            }
            for(int i = t + 1; i <= b; i++)
            {
                if(head == NULL) return ans;
                ans[i][r] = head->val;
                head = head->next;
            }
            for(int i = r - 1; i >= l; i--)
            {
                if(head == NULL) return ans;
                ans[b][i] = head->val;
                head = head->next;
            }
            for(int i = b - 1; i > l; i--)
            {
                if(head == NULL) return ans;
                ans[i][l] = head->val;
                head = head->next;
            }
            l++;
            t++;
            r--;
            b--;
        }
        return ans;
    }
};