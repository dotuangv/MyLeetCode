class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>> &path, vector<bool> &visited, int i)
    {
        visited[i] = true;
        for(int j = 0; j < path[i].size(); j++)
        {
            if(!visited[path[i][j]])
            {
                dfs(path, visited, path[i][j]);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> path(isConnected.size());
        for(int i = 0; i < isConnected.size(); i++)
        {
            for(int j = 0; j < isConnected[i].size(); j++)
            {
                if(isConnected[i][j] && i < j)
                {
                    path[i].push_back(j);
                    path[j].push_back(i);
                }
            }
        }
        vector<bool> visited(isConnected.size());
        int ans = 0;
        for(int i = 0; i < isConnected.size(); i++)
        {
            if(!visited[i])
            {
                ans++;
                dfs(path, visited, i);
            }
        }
        return ans;
    }
};