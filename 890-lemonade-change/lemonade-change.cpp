class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        ios::sync_with_stdio(false); cin.tie(nullptr);
        unordered_map<int, int> mp;
        for(auto &x: bills)
        {
            if(x == 5) mp[5]++;
            else if(x == 10)
            {
                if(!mp[5]) return false;
                mp[5]--;
                mp[10]++;
            }else
            {
                int x = 15;
                if(mp[10])
                {
                    x -= 10;
                    mp[10]--;
                }
                if(mp[5] < x/5) return false;
                mp[5] -= x/5;
            }
        }
        return true;
    }
};