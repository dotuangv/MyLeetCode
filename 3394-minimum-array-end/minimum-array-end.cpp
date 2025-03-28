class Solution {
public:
    long long minEnd(int n, int x) {
        bitset<64> a(x), b(n - 1);
        vector<int> vt;
        for(int i = 0; i < 50; i++)
            if(a[i] == 0) vt.push_back(i);
        int j = 0;
        for(int i = 0; i < 50; i++)
        {
            if(j >= vt.size()) break;
            a[vt[j++]] = b[i];
        }
        return a.to_ulong();
        
    }
};