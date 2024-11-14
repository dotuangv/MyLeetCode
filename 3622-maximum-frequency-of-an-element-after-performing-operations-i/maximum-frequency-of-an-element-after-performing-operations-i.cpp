class Solution {
public:
    
    int upper(long long x, vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while(r > l + 1)
        {
            int mid = (l + r)/2;
            if(nums[mid] <= x) l = mid;
            else r = mid;
        }
        if(nums[r] <= x) return r;
        else if(nums[l] <= x) return l;
        return -1;
    }
    
    int lower(long long x, vector<int> &nums)
    {
        int l = 0, r = nums.size() - 1;
        while(r > l + 1)
        {
            int mid = (l + r)/2;
            if(nums[mid] >= x) r = mid;
            else l = mid;
        }
        if(nums[l] >= x) return l;
        else if(nums[r] >= x) return r;
        return -1;
    }
    
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        for(auto x: nums) mp[x]++;
        int ans = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            int r = upper(nums[i] + k, nums), l = lower(nums[i] - k, nums);
            int res = 0;
            if(l != -1) res += i - l;
            if(r != -1) res += r - i;
            res++;
            ans = max(ans, mp[nums[i]] + min(res - mp[nums[i]], numOperations));
        }
        
        for(int i = 0; i < nums.size(); i++)
        {
            int r = upper(nums[i] + 2*k, nums);
            ans = max(ans, min(r - i + 1, numOperations));
        }
        return ans;
        
    }
};