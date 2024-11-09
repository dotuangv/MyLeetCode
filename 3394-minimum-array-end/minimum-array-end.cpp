class Solution {
public:
    long long minEnd(int n, int x) {
        if(n == 1) return x;
        bitset<64> a(x);
        vector<int> vt;
        for(int i = 0; i < 64; i++)
        {
            if(a[i] == 0) vt.push_back(i);
        }
        bitset<64> b(n - 1);
        int j = 0;
        for(int i = 0; i < 64; i++)
        {
            if(j >= vt.size()) break;
            a[vt[j++]] = b[i];
        }
        long long ans = a.to_ulong();

        return ans;
        
    }
};