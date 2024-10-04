class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<int, long long> mp;
        long long ans = 0, sum = 0;
        for(auto x: skill) {mp[x]++; sum += x;}
        if(sum % (skill.size()/2)) return -1;
        sum = sum/(skill.size()/2);
        for(auto x: mp)
        {
            if(mp[x.first])
            {
                if(!mp.contains(sum - x.first)) return -1;
                else
                {
                    if(x.first*2 == sum)
                    {
                        if(mp[x.first] % 2 != 0) return -1;
                        else ans += mp[x.first]/2 * x.first * x.first;
                    }else 
                    {
                        if(mp[x.first] != mp[sum - x.first]) return -1;
                        else ans += mp[x.first] * x.first * (sum - x.first);
                        mp[x.first] = 0;
                        mp[sum - x.first] = 0;
                    }
                }
            }
        }
        return ans;

    }
};