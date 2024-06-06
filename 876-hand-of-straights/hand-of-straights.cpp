class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        if(hand.size() % groupSize) return false;
        sort(hand.begin(), hand.end());
        map<int, int> mp;
        for(auto x: hand) mp[x]++;
        for(auto &x: mp)
        {
            // cout << x.first << " " << x.second << "\n";
            if(x.second > 0)
            {
                for(int i = x.first + 1; i < x.first + groupSize; i++)
                {
                    if(mp[i] < x.second) return false;
                    mp[i] -= x.second;
                }
            }else if(x.second < 0) return false;
        }
        return true;
    }
};