#include <vector>
#include <string>
using namespace std;

#define ll long long

class Solution {
public:
    int MOD = 1e9 + 7;

    vector<vector<ll>> Mul(const vector<vector<ll>> &vt1, const vector<vector<ll>> &vt2) {
        vector<vector<ll>> result(26, vector<ll>(26, 0));
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ll sum = 0;
                for (int k = 0; k < 26; k++) {
                    sum = (sum + vt1[i][k] * vt2[k][j]) % MOD;
                }
                result[i][j] = sum;
            }
        }
        return result;
    }

    vector<vector<ll>> pow(int n, vector<vector<ll>> &vt) {
        vector<vector<ll>> result(26, vector<ll>(26, 0));
        for (int i = 0; i < 26; i++) result[i][i] = 1; // Identity matrix
        
        while (n > 0) {
            if (n % 2 == 1) {
                result = Mul(result, vt);
            }
            vt = Mul(vt, vt);
            n /= 2;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<ll>> vt1(26, vector<ll>(26, 0));
        for (auto x : s) vt1[x - 'a'][x - 'a']++;

        vector<vector<ll>> vt2(26, vector<ll>(26, 0));
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= nums[i]; j++) {
                vt2[i][(i + j) % 26]++;
            }
        }

        vt1 = Mul(vt1, pow(t, vt2));

        int ans = 0;
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ans = (ans + vt1[i][j]) % MOD;
            }
        }
        return ans;
    }
};
