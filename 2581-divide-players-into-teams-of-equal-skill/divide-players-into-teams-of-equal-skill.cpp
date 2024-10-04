class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        vector<long long> mp(1001);
        long long ans = 0, sum = 0;
        for(auto x: skill) {mp[x]++; sum += x;}
        if(sum % (skill.size()/2)) return -1;
        sum = sum/(skill.size()/2);
        for(int x = 1; x <= 1000; x++)
        {
            if(mp[x] != 0)
            {
                if(sum - x < 0) return -1;
                else
                {
                    if(x*2 == sum)
                    {
                        if(mp[x] % 2 != 0) return -1;
                        else ans += mp[x]/2 * x * x;
                    }else 
                    {
                        if(mp[x] != mp[sum - x]) return -1;
                        else ans += mp[x] * x * (sum - x);
                        mp[x] = 0;
                        mp[sum - x] = 0;
                    }
                }
            }
        }
        return ans;

    }
};