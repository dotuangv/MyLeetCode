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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, bool> mp;
        for(auto &x: nums) mp[x] = true;
        vector<int> ans;
        while(head != NULL)
        {
            if(!mp[head->val]) ans.push_back(head->val);
            head = head->next;
        }
        if(ans.size() == 0) return NULL;
        ListNode * res = new ListNode(ans.back());
        for(int i = ans.size() - 2; i >= 0; i--)
        {
            ListNode *tmp = new ListNode(ans[i], res);
            res = tmp;
        }
        return res;
        
    }
};