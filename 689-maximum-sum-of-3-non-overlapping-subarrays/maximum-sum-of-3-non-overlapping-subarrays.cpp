class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1, 0);

        // Tính tổng tiền tố
        for (int i = 1; i <= n; i++) {
            pre[i] = pre[i - 1] + nums[i - 1];
        }

        // dp[i][j]: Tổng lớn nhất với j khoảng con và kết thúc tại vị trí i
        vector<vector<long long>> dp(n + 1, vector<long long>(4, 0));
        vector<vector<int>> pos(n + 1, vector<int>(4, -1));

        for (int j = 1; j <= 3; j++) {
            for (int i = j * k; i <= n; i++) {
                long long sum = pre[i] - pre[i - k];
                if (dp[i - 1][j] < dp[i - k][j - 1] + sum) {
                    dp[i][j] = dp[i - k][j - 1] + sum;
                    pos[i][j] = i - k + 1;
                } else {
                    dp[i][j] = dp[i - 1][j];
                    pos[i][j] = pos[i - 1][j];
                }
            }
        }

        // Truy ngược lại để tìm vị trí
        vector<int> result(3);
        int index = n;
        for (int j = 3; j > 0; j--) {
            result[j - 1] = pos[index][j] - 1;
            index = result[j - 1];
        }

        return result;
    }
};
