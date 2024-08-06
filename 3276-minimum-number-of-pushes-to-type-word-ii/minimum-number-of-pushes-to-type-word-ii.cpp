#include <execution>
auto f = [] {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();
class Solution {
public:
    int minimumPushes(string word) {
        array<int, 26> f {};
        for (char c : word) {
            f[c - 'a']++;
        }
        sort(execution::par_unseq, f.begin(), f.end(), greater{});
        return transform_reduce(execution::par_unseq, f.begin(), f.end(), 0, plus{}, [f = &f[0]](int const& x) { 
            int i = &x - f;
            return x * (i / 8 + 1);
        });
    }
};