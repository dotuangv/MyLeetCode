class Solution {
public:

    vector<int> vt;
    int change = 0;
    int Solve(int k, int n)
    {
        if(n == 1 || k == 1) return 0;
        if(k == vt[n]/2 + 1) return 1;
        if(k <= vt[n]/2)
        {
            return Solve(k, n - 1);
        }else
        {
            change++;
            k = vt[n] - k + 1;
            return Solve(k, n - 1);
        }

    }

    char findKthBit(int n, int k) {
        vt.resize(n + 1);
        for(int i = 1; i <= n; i++)
        {
            vt[i] = vt[i - 1] * 2 + 1;
        }
        int ans = Solve(k, n);
        if(ans)
        {
            if(change % 2) return '0';
            else return '1';
        }else
        {
            if(change % 2) return '1';
            else return '0';
        }

    }
};