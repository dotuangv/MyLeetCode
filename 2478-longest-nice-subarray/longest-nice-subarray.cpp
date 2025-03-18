class Solution {
public:
    bool check(queue<int> q, int x){
        while(!q.empty()){
            if((x & q.front()) != 0) return false;
            q.pop();
        }
        return true;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int ans = 1;
        queue<int> q;
        int r = 0;
        while(r < nums.size()){
            if(check(q, nums[r])){
                q.push(nums[r]);
                r++;
                ans = max(ans, int(q.size()));
            }else{
                q.pop();
            }
        }
        return ans;
    }
};