class Solution {
public:
    int dist(int size, int p, int t){
        return min(abs(t - p), size - abs(t - p));
    }
    int findRotateSteps(string ring, string key){
        int m[26][100] = {{0}};
        int cnt[26] = {0};
        int dp[100][100] = {{0}};

        const int rn = ring.size();
        const int kn = key.size();
        for(int i = 0; i < rn; ++i)
            m[ring[i]-'a'][cnt[ring[i]-'a']++] = i;

        for(int i = 0; i < cnt[key[0]-'a']; ++i){
                dp[0][m[key[0]-'a'][i]] = dist(rn, 0, m[key[0]-'a'][i]) + 1;
        }
        for(int i = 1; i < kn; ++i){
            for(int j = 0; j < cnt[key[i]-'a']; ++j){
                int mini = INT_MAX;
                for(int k = 0; k < cnt[key[i-1]-'a']; ++k){
                    mini = min(mini, dp[i-1][m[key[i-1]-'a'][k]] + dist(rn, m[key[i]-'a'][j], m[key[i-1]-'a'][k]) + 1);
                }
                dp[i][m[key[i]-'a'][j]] = mini;
            }
        }
        int res = INT_MAX;
        for(int i = 0; i < cnt[key.back()-'a']; ++i){
            res = min(res, dp[kn-1][m[key[kn-1]-'a'][i]]);
        }
        return res;
    }
};