class Solution {
public:
    int convert(int nums){
        int sum = 0;
        while(nums){
            sum += nums % 10;
            nums /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < nums.size(); i++){
            mp[convert(nums[i])].push_back(nums[i]);
        }
        int ans = -1;
        for(auto &[x, y]: mp){
            if(y.size() < 2) continue;
            int Max1 = max(y[0], y[1]), Max2 = min(y[0], y[1]);
            for(int i = 2; i < y.size(); i++){
                Max2 = max(Max2, min(Max1, y[i]));
                Max1 = max(Max1, y[i]);
            }
            ans = max(ans, Max1 + Max2);
        }
        return ans;
    }
};