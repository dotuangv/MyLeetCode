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
    ListNode* doubleIt(ListNode* head) {
        stack<int> st;
        while(head != NULL)
        {
            st.push(head->val);
            head = head -> next;
        }
        int tmp = 0;
        ListNode *ans = NULL;
        while(!st.empty())
        {
            tmp += st.top() * 2;
            ListNode *res = new ListNode(tmp % 10, ans);
            ans = res;
            tmp /= 10;
            st.pop();
        }
        if(tmp)
        {
            ListNode *res = new ListNode(tmp, ans);
            ans = res;
        }
        return ans;
    }
};