class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end());
        int n = nums.size(), m = queries.size(), k = 0, cnt = 0;
        priority_queue<int> available;
        priority_queue<int, vector<int>, greater<int>> assigned;
        for(int i = 0; i < n; i++){
            while(!assigned.empty() && assigned.top() < i) assigned.pop();
            while(k < m && queries[k][0] <= i) available.push(queries[k++][1]);
            while(assigned.size() < nums[i] && !available.empty() && available.top() >= i){
                assigned.push(available.top());
                available.pop();
                cnt++;
            }
            if(assigned.size() < nums[i]) return -1;
        }
        return m - cnt;
    }
};