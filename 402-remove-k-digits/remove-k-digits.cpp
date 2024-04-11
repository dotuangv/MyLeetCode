class Solution {
public:
    string removeKdigits(string nums, int k) {
        if(nums.size() == k) return "0";
        string ans = "";
        int zero = 0;
        for(int i = 0; i < nums.size(); i++)
        {
            if(k != 0)
            {
                while(k && ans.size() > 0 && nums[i] < ans.back())
                {
                    k--;
                    ans.pop_back();
                }
                ans += nums[i];
            }else
            {
                for(int j = i; j < nums.size(); j++)
                {
                    ans += nums[j];
                }
                break;
            }
        }
        if(k > 0)
        {
            while(k--) ans.pop_back();
        }

        string s = "";
        int i = 0;
        while(i < ans.size())
        {
            if(ans[i] != '0') break;
            i++;
        }
        while(i < ans.size()) s += ans[i++];
        if(s.size() == 0) s += '0';
        return s;
    }
};