class Solution {
public:
    void dfs(int cur, vector<vector<int>> &path, vector<int> &height, vector<bool> &visited, bool &ok){
        visited[cur] = true;
        if(cur == 0){
            ok = true;
            return;
        }
        for(auto x: path[cur]){
            if(!visited[x]){
                height[x] = height[cur] + 1;
                dfs(x, path, height, visited, ok);
                if(!ok) height[x] = -1;
                else return;
            }
        }
        if(ok) return;
    }
    int result = -1e9;
    void dfs2(int cur, vector<vector<int>> &path, vector<int> &height, vector<bool> &visited, vector<int> &amount, int sum, int res){
        visited[cur] = true;
        int tmp = sum;
        if(res == height[cur]) tmp += amount[cur]/2;
        else if(res < height[cur] || height[cur] == -1) tmp += amount[cur];
        if(path[cur].size() < 2 && cur != 0){
            result = max(result, tmp);
        }

        for(auto x: path[cur]){
            if(!visited[x]){
                dfs2(x, path, height, visited, amount, tmp, res + 1);
            }
        }
    }

    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        vector<vector<int>> path(edges.size() + 1);
        for(auto &x: edges){
            path[x[0]].push_back(x[1]);
            path[x[1]].push_back(x[0]);
        }
        bool ok = false;
        vector<int> height(path.size(), -1);
        vector<bool> visited(path.size());
        height[bob] = 0;
        dfs(bob, path, height, visited, ok);
        for(int i = 0; i < visited.size(); i++) visited[i] = false;
        dfs2(0, path, height, visited, amount, 0, 0);
        return result;
    }
};