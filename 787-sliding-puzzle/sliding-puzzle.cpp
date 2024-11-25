class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, vector<vector<int>>> &a, 
                        const pair<int, vector<vector<int>>> &b) {
            return a.first > b.first;
        }
    };

    int slidingPuzzle(vector<vector<int>>& board) {
        map<vector<vector<int>>, bool> check;
        vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 0}};
        queue<pair<int, vector<vector<int>>>> q;
        int xd[] = {-1, 0, 1, 0};
        int yd[] = {0, -1, 0, 1};
        q.push({0, board});
        check[board] = true;
        while(!q.empty()){
            int g = q.front().first;
            vector<vector<int>> tmp = q.front().second;
            q.pop();
            bool ok = true;
            int x, y;
            for(int i = 0; i < tmp.size(); i++){
                for(int j = 0; j < tmp[i].size(); j++){
                    if(tmp[i][j] != goal[i][j]) ok = false;
                    if(tmp[i][j] == 0){
                        x = i, y = j;
                    }
                }
            }
            if(ok) return g;
            for(int i = 0; i < 4; i++){
                int ii = x + xd[i], jj = y + yd[i];
                if(ii >= 0 && ii < 2 && jj >= 0 && jj < 3){
                    vector<vector<int>> res = tmp;
                    swap(res[x][y], res[ii][jj]);
                    if(!check[res]) {
                        q.push({g + 1, res});
                        check[res] = true;
                    }
                }
            }
        }
        return -1;
    }
};