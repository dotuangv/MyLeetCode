#include <vector>
#include <string>
using namespace std;

#define ll long long

class Solution {
public:
    int MOD = 1e9 + 7;

    // Hàm Mul tối ưu bằng cách hạn chế phép cộng và % nhiều lần
    vector<vector<ll>> Mul(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
        vector<vector<ll>> result(26, vector<ll>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int k = 0; k < 26; ++k) {
                if (a[i][k] == 0) continue;  // Bỏ qua các phần tử bằng 0
                for (int j = 0; j < 26; ++j) {
                    result[i][j] = (result[i][j] + a[i][k] * b[k][j] % MOD) % MOD;
                }
            }
        }
        return result;
    }

    // Hàm pow tối ưu bằng cách giảm tạo mới ma trận
    vector<vector<ll>> pow(int n, vector<vector<ll>> &base) {
        vector<vector<ll>> result(26, vector<ll>(26, 0));
        for (int i = 0; i < 26; i++) result[i][i] = 1;  // Identity matrix

        while (n > 0) {
            if (n & 1) {
                result = Mul(result, base);
            }
            base = Mul(base, base);
            n >>= 1;
        }
        return result;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<vector<ll>> vt1(26, vector<ll>(26, 0));
        for (char x : s) vt1[x - 'a'][x - 'a']++;

        vector<vector<ll>> vt2(26, vector<ll>(26, 0));
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= nums[i]; j++) {
                vt2[i][(i + j) % 26]++;
            }
        }

        // Tối ưu phép tính mũ
        vt1 = Mul(vt1, pow(t, vt2));

        int ans = 0;
        for (const auto& row : vt1)
            for (ll val : row)
                ans = (ans + val) % MOD;

        return ans;
    }
};
