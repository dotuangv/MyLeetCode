class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        vector<pair<int, pair<int, int>>> v;
        int cnt = 1;
        for(int i = 0; i < events.size(); i++){
            v.push_back({events[i][0], {i, 0}});
            v.push_back({events[i][1], {i, 1}});
        }
        sort(v.begin(), v.end());
        events[v[0].second.first][v[0].second.second] = cnt++;
        for(int i = 1; i < v.size(); i++){
            if(v[i].first == v[i - 1].first){
                events[v[i].second.first][v[i].second.second] = events[v[i - 1].second.first][v[i - 1].second.second];
            }else  events[v[i].second.first][v[i].second.second] = cnt++;
        }
        vector<vector<pair<int, int>>> vt(cnt);
        for(int i = 0; i < events.size(); i++){
            cout << events[i][0] << " " << events[i][1] << " " << events[i][2] << "\n";
            vt[events[i][1]].push_back({events[i][0], events[i][2]});
        }
        vector<int> dp(cnt);
        int ans = 0;
        for(int i = 1; i < cnt; i++){
            dp[i] = dp[i - 1];
            for(auto x: vt[i]){
                ans = max(ans, dp[x.first - 1] + x.second);
                dp[i] = max(dp[i], x.second);
            }
        }
        return ans;
    }
};