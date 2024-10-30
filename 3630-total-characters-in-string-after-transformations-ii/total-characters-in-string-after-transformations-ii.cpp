#define ll long long
class Solution {
public:
    int MOD = 1e9 + 7;
    vector<vector<ll>> Mul(vector<vector<ll>> vt1, vector<vector<ll>> vt2)
    {
        vector<vector<ll>> result(26, vector<ll> (26));
        for(int i = 0; i < 26; i++)
        {
            for(int j = 0; j < 26; j++)
            {
                for(int k = 0; k < 26; k++)
                {
                    result[i][j] += (vt1[i][k] % MOD) * (vt2[k][j] % MOD);
                    result[i][j] %= MOD;
                }
            }
        }
        return result;
    }

    vector<vector<ll>> pow(int n, vector<vector<ll>> vt)
    {
        vector<vector<ll>> result(26, vector<ll> (26));
        for(int i = 0; i < 26; i++) result[i][i] = 1;
        while(n)
        {
            if(n % 2)
            {
                result = Mul(result, vt);
            }
            vt = Mul(vt, vt);
            n/=2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        int MOD = 1e9 + 7;
        vector<vector<ll>> vt1(26, vector<ll> (26));
        for(auto x: s) vt1[x - 'a'][x - 'a']++;
        vector<vector<ll>> vt2(26, vector<ll> (26));
        for(int i = 0; i < nums.size(); i++)
        {
            for(int j = 1; j <= nums[i]; j++)
            {
                vt2[i][(i + j)%26]++;
            }
        }
        vt1 = Mul(vt1, pow(t, vt2));
        int ans = 0;
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++) {
                ans += vt1[i][j];
                ans %= MOD;
            }
        return ans;
        
    }
};