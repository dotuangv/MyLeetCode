class Solution {
public:
    vector<int> ans;

    int dfs(int i, vector<vector<int>> &graph, vector<int> c, string &s)
    {
        if(graph[i].empty()) return ans[i] = 1;
        int res = 1;
        c[s[i] - 'a'] = i;
        for(auto x: graph[i])
        {
            if(c[s[x] - 'a'] == -1) res += dfs(x, graph, c, s);
            else ans[c[s[x] - 'a']] += dfs(x, graph, c, s);
        }
        return ans[i] += res;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        ans.resize(s.size());
        vector<vector<int>> graph(s.size());
        vector<int> c(26, -1);
        for(int i = 1; i < parent.size(); i++) graph[parent[i]].push_back(i);
        dfs(0, graph, c, s);
        return ans;
    }
};