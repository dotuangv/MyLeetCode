#pragma GCC optimize("Ofast", "inline", "fast-math", "unroll-loops", "no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native", "f16c")

#include <emmintrin.h>

static bool _ = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return false;
}();

static short dp[10008] __attribute__((aligned(16)));
static __m128i zero = _mm_set1_epi32(0);
static int buf[8];

class Solution {
public:
    static __attribute__((always_inline)) int openLock(const vector<string>& deadends, const string_view target) {
        const int t = si(target);
        if (t == 0) {
            return 0;
        }
        for (int i = 0; i < 10008; i += 8) {
            _mm_store_si128((__m128i *) &dp[i], zero);
        }
        dp[0] = 1;
        for (const auto& s: deadends) {
            dp[si(s)] = -1;
        }
        if (dp[0] == -1) {
            return -1;
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int top = q.front();
            q.pop();
            getAllAdj(top);
            for (int i: buf) {
                if (i == t) {
                    return dp[top];
                }
                if (dp[i] == 0) {
                    dp[i] = dp[top] + 1;
                    q.push(i);
                }
            }
        }
        return -1;
    }

    static constexpr __attribute__((always_inline)) int si(const string_view s) {
        return (s[3] - '0') + 10 * (s[2] - '0') + 100 * (s[1] - '0') + 1000 * (s[0] - '0');
    }

    static __attribute__((always_inline)) int getAllAdj(int s) {
        int cnt = 0, cp = s;
        for (const int diff : {1, 10, 100, 1000}) {
            switch (cp % 10) {
                case 0:
                    buf[cnt++] = s + diff;
                    buf[cnt++] = s + 9 * diff;
                    break;
                case 9:
                    buf[cnt++] = s - diff;
                    buf[cnt++] = s - 9 * diff;
                    break;
                default:
                    buf[cnt++] = s + diff;
                    buf[cnt++] = s - diff;
            }
            cp /= 10;
        }
        return cnt;
    }
};