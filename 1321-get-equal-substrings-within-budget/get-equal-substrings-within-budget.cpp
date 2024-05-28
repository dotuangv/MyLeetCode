class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        vector<int> nums(n, 0);
        for(int i = 0; i < n; i++)
            nums[i] = abs(s[i] - t[i]);
        int start = 0, end = 0;
        int ans = 0;
        int sum = 0;
        while(end < n) {
            sum += nums[end];
            while(start <= end && sum > maxCost) {
                sum -= nums[start];
                start++;
            }
            ans = max(ans, end - start + 1);
            end++;
        }
        return ans;
    }
};