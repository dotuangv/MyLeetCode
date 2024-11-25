class Solution {
public:

    string to_String(vector<vector<int>> &board){
        string result = "";
        for(int i = 0; i < 2; i++){
            for(int j = 0; j < 3; j++) result.push_back(board[i][j] - '0');
        }
        return result;
    }

    int slidingPuzzle(vector<vector<int>>& board) {
        unordered_map<string, bool> check;
        vector<vector<int>> goal = {{1, 2, 3}, {4, 5, 0}};
        queue<pair<int, vector<vector<int>>>> q;
        int xd[] = {-1, 0, 1, 0};
        int yd[] = {0, -1, 0, 1};
        q.push({0, board});
        check[to_String(board)] = true;
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
                    string s = to_String(res);
                    if(!check[s]) {
                        q.push({g + 1, res});
                        check[s] = true;
                    }
                }
            }
        }
        return -1;
    }
};