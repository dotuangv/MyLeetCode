class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto &x: nums) pq.push(x);
        int ans = 0;
        while(pq.top() < k){
            long long x = pq.top();
            pq.pop();
            x = x * 2 + pq.top();
            pq.pop();
            pq.push(x);
            ans++;
        }
        return ans;
    }
};