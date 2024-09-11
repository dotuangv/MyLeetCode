class Solution {
public:
    int minBitFlips(int start, int goal) {
        bitset<32> a(start), b(goal);
        int ans = 0;
        for(int i = 0; i < 32; i++) ans += (a[i] != b[i]);
        return ans;
    }
};