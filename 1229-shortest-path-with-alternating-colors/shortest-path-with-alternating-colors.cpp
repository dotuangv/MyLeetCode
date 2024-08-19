class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> ans(n, 1e9);
        ans[0] = 0;
        vector<vector<int>> Rpath(n), Bpath(n);
        for(auto x: redEdges)
        {
            Rpath[x[0]].push_back(x[1]);
        }
        for(auto x: blueEdges)
        {
            Bpath[x[0]].push_back(x[1]);
        }
        queue<pair<int, pair<int, bool>>> q;
        vector<bool> Rcheck(n), Bcheck(n);
        Rcheck[0] = true;
        Bcheck[0] = true;
        for(auto x: Rpath[0])
        {
            q.push({x, {1, true}});
            ans[x] = min(ans[x], 1);
            Rcheck[x] = true;
        }
        for(auto x: Bpath[0])
        {
            q.push({x, {1, false}});
            ans[x] = min(ans[x], 1);
            Bcheck[x] = true;
        }
        while(!q.empty())
        {
            pair<int, pair<int, bool>> p = q.front();
            q.pop();
            if(p.second.second)
            {
                Rcheck[p.first] = true;
                for(auto x: Bpath[p.first])
                {
                    if(!Bcheck[x])
                    {
                        q.push({x, {p.second.first + 1, false}});
                        ans[x] = min(ans[x], p.second.first + 1);
                    }
                }
            }else
            {
                Bcheck[p.first] = true;
                for(auto x: Rpath[p.first])
                {
                    if(!Rcheck[x])
                    {
                        q.push({x, {p.second.first + 1, true}});
                        ans[x] = min(ans[x], p.second.first + 1);
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) 
            if(ans[i] == 1e9) ans[i] = -1;
        return ans;
    }
};