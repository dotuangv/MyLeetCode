#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
#pragma GCC optimize ("O3", "unroll-loops")
#pragma GCC optimize ("-ffloat-store")

auto init = []() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
} ();

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) const {
        std::sort(folder.begin(), folder.end());

        std::vector<std::string> ans; ans.reserve(folder.size());
        ans.push_back(std::move(folder.front()));

        size_t i{1};
        while(i < folder.size()) {
            if (!folder[i].starts_with(ans.back()+'/')) {
                ans.push_back(std::move(folder[i]));
            }
            ++i;
        }

        return ans;
    }
};