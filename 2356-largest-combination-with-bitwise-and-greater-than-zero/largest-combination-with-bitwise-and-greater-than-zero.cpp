auto init = []() { 
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    return 0;
} ();
class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> count(30);
        for(int i = 0; i < candidates.size(); i++)
        {
            bitset<32> b(candidates[i]);
            for(int i = 0; i < 30; i++) count[i] += b[i];
        }
        int ans = 0;
        for(int i = 0; i < 30; i++) ans = max(ans, count[i]);
        return ans;
    }
};