class Solution {
public:
    int trie[300005][26];
    int cnt = 0;
    bool ok[300005];
    int x[4] = {-1, 0, 0, 1};
    int y[4] = {0, -1, 1, 0};
    vector<vector<bool>> visit;
    vector<string> ans;
    void Insert(string &s)
    {
        int u = 0;
        for(int i = 0; i < s.size(); i++)
        {
            int k = s[i] - 'a';
            if(!trie[u][k]) trie[u][k] = ++cnt;
            u = trie[u][k];
        }
        ok[u] = true;
    }

    void Backtrack(int i, int j, int u, vector<vector<char>> &board, string s)
    {
        visit[i][j] = true;
        int k = board[i][j] - 'a';
        if(trie[u][k])
        {
            if(ok[trie[u][k]])
            {
                ok[trie[u][k]] = false;
                ans.push_back(s + board[i][j]);
            }
                for(int l = 0; l < 4; l++)
                {
                    int ii = i + x[l];
                    int jj = j + y[l];
                    if(ii >= 0 && ii < board.size() && jj >= 0 && jj < board[ii].size() && !visit[ii][jj])
                    {
                        Backtrack(ii, jj, trie[u][k], board, s + board[i][j]);
                        visit[ii][jj] = false;
                    }
                }
        }else return;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for(int i = 0; i < words.size(); i++)
            Insert(words[i]);
        visit.resize(board.size(), vector<bool> (board[0].size()));

        for(int i = 0; i < board.size(); i++)
        {
            for(int j = 0; j < board[i].size(); j++)
            {
                Backtrack(i, j, 0, board, "");
                visit[i][j] = false;
            }
        }
        return ans;
    }
};