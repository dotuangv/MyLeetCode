class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        for(int i = nums.size() - 1; i >= 0; i--) st.push(nums[i]);
        int ans = 0;
        while(!st.empty()){
            int x = st.top();
            st.pop();
            if(x == 0){
                if(st.size() < 2) return -1;
                vector<int> a;
                for(int i = 0; i < 2; i++){
                    a.push_back(st.top());
                    st.pop();
                }
                for(int i = 1; i >= 0; i--){
                    st.push(!a[i]);
                }
                ans++;
            }
        }
        return ans;
    }
};