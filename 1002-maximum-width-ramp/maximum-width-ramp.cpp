class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        stack<int> st;
        
        st.push(0);

        for(int i = 1; i < n; i++){
            if(nums[st.top()] > nums[i]){
                st.push(i);
            }
        }

        int ans = 0;

        for(int i = n-1; i >= 0; ){

            while(!st.empty() and nums[st.top()] <= nums[i]){
                ans = max(ans, i - st.top());
                st.pop();
            }

            if(st.empty()) break;

            i--;
        }

        return ans;

    }
};

/*
https://www.youtube.com/watch?v=_TkAgiKixAk&ab_channel=Codekitchen%7CNewtonschool

use the stack to solve it

n^2 for brute force

put the numbers in decreading order in the stack for all the elements

then just iterate from right to compare with the top element

whenever you found someone to compare with the top: remove it because it can not again contribute in maximum

*/