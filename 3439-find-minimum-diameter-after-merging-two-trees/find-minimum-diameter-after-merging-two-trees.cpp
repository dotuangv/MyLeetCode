class Solution {
public:
    
    int dist(int i, vector<vector<int>> &path, vector<bool> &visit, int &Max){
        visit[i] = true;
        int sum = 0;
        for(auto x: path[i]){
            if(!visit[x]) {
                int d = dist(x, path, visit, Max);
                Max = max(Max, sum + d + 1);
                sum = max(sum, 1 + d);
            }
        }
        return sum;
    }



    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> path1(n), path2(m);
        for(int i = 0; i < edges1.size(); i++){
            path1[edges1[i][0]].push_back(edges1[i][1]);
            path1[edges1[i][1]].push_back(edges1[i][0]);
        }
        for(int i = 0; i < edges2.size(); i++){
            path2[edges2[i][0]].push_back(edges2[i][1]);
            path2[edges2[i][1]].push_back(edges2[i][0]);
        }
        // bfs(path2);
        // int res1 = 1e9, res2 = 1e9;
        // for(auto x: bfs(path1)){
        //     cout << x << "\n";
        //     res1 = min(res1, dist(x, path1, visit1));
        // }
        // for(auto x: bfs(path2)){
        //     vector<bool> visit2(m);
        //     res2 = min(res2, dist(x, path2, visit2));
        // }
        vector<bool> visit1(n), visit2(m);

        int Max1 = 0, Max2 = 0, D1 = dist(0, path1, visit1, Max1), D2 = dist(0, path2, visit2, Max2);
        return max({Max1, Max2, (Max1 + 1)/2 + (Max2 + 1)/2 + 1});
        // cout << bfs(path1) << " " << bfs(path2) << "\n";
        // cout << dist(bfs(path1), path1, visit1) << " " << dist(bfs(path2), path2, visit2) << "\n";
        return 0;
    }
};