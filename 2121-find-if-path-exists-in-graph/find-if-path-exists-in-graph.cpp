class Solution {
public:
    bool dfs(int i, vector<vector<int>> &path, vector<bool> &visit, int destination)
    {
        if(i == destination) return true;
        bool ok = false;
        visit[i] = true;
        for(int j = 0; j < path[i].size(); j++)
        {
            if(!visit[path[i][j]])
            {
                ok = (ok || dfs(path[i][j], path, visit, destination));
            }
        }
        return ok;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> path(n);
        for(auto x: edges)
        {
            path[x[0]].push_back(x[1]);
            path[x[1]].push_back(x[0]);
        }
        vector<bool> visit(n);
        return dfs(source, path, visit,destination);
    }
};