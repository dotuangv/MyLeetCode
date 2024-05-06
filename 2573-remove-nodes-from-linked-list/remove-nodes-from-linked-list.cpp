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
    ListNode* removeNodes(ListNode* head) {
        std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
        stack<int> st;
        while(head != NULL)
        {
            if(st.empty()) st.push(head->val);
            else
            {
                while(!st.empty() && st.top() < head->val) st.pop();
                st.push(head->val);
            }
            head = head->next;
        }
        ListNode *ans = new ListNode(st.top());
        st.pop();
        while(!st.empty())
        {
            ListNode *tmp = new ListNode(st.top(), ans);
            ans = tmp;
            st.pop();
        }
        return ans;
    }
};