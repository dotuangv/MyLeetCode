struct Trie {
    Trie* child[26] = {0};
    bool end = false;
};

class Solution
{
	public:
		bool dfs(int i, int j, int k, vector<vector < char>> &board, string &search, int &row, int &col)
		{
			if (i == search.size())
				return true;
			if (j >= 0 and j < row and k >= 0 and k < col)
			{
				if (board[j][k] != search[i])
					return false;
				char realChild = board[j][k];
				board[j][k] = '$';
				bool ans = dfs(i + 1, j + 1, k, board, search, row, col) ||
					dfs(i + 1, j - 1, k, board, search, row, col) ||
					dfs(i + 1, j, k + 1, board, search, row, col) ||
					dfs(i + 1, j, k - 1, board, search, row, col);
				board[j][k] = realChild;
				return ans;
			}
			else
				return false;
		}
	vector<string> findWords(vector<vector < char>> &board, vector< string > &words)
	{
		int row = board.size();
		int col = board[0].size();
		vector<string> ans;
		vector<vector<pair<int, int>>> vecp(27);
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
				vecp[board[i][j] - 'a'].push_back({ i, j });
		}
		int start = 0;
		int end = 0;
		for (auto element: words)
		{
			if (element[0] == 'a')
				start++;
			if (element[element.size() - 1] == 'a')
				end++;
		}
		bool checkReverse = false;
		if (start > end)
		{
			checkReverse = true;
			for (int i = 0; i < words.size(); i++)
				reverse(words[i].begin(), words[i].end());
		}
		for (auto search: words)
		{
			bool flag = false;
			for (auto element: vecp[search[0] - 'a'])
			{
				flag = dfs(0, element.first, element.second, board, search, row, col);
				if (flag)
				{
					if (checkReverse)
						reverse(search.begin(), search.end());

					ans.push_back(search);
					break;
				}
			}
		}
		return ans;
	}
};