class Solution {
public:
    int smallestNumber(int n) {
        int mask = 1 << int(log2(n) + 1);
        return n | (mask - 1);
    }
};