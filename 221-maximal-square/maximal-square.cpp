const static auto fast = []
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int ans = 0;
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size()));
        for(int i = 0; i < matrix.size(); i++) 
        {
            dp[i][0] = matrix[i][0] - '0';
            if(!ans) ans = dp[i][0];
        }
        for(int i = 0; i < matrix[0].size(); i++)
        {
            dp[0][i] = matrix[0][i] - '0';
            if(!ans) ans = dp[0][i];
        }
        for(int i = 1; i < matrix.size(); i++)
        {
            for(int j = 1; j < matrix[0].size(); j++)
            {
                dp[i][j] = matrix[i][j] - '0';
                if(dp[i][j])
                {
                    dp[i][j] = min({dp[i][j - 1], dp[i - 1][j - 1], dp[i - 1][j]}) + 1;
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans*ans;
    }
};