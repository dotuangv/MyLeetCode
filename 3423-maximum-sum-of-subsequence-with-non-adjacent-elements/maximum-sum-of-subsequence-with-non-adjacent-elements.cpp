class Solution {
public:
    struct Node
    {
        long long a;
        long long b;
        long long ab;
        long long c;
    };
    void build(int id, int l, int r, vector<Node> &ST, vector<int> &nums)
    {
        if(l == r)
        {
            ST[id].ab = max(0, nums[l]);
            return;
        }
        int mid = (l + r)/2;
        build(2*id + 1, l, mid, ST, nums);
        build(2*id + 2, mid + 1, r, ST, nums);
        Node t1 = ST[id*2 + 1], t2 = ST[id*2 + 2];
        ST[id].ab = max({t1.a + t2.ab, t1.a + t2.b, t1.ab + t2.b});
        ST[id].a = max({t1.a + t2.a, t1.a + t2.c, t1.ab + t2.c});
        ST[id].b = max({t1.b + t2.b, t1.c + t2.b, t1.c + t2.ab});
        ST[id].c = max({t1.b + t2.c, t1.c + t2.c, t1.c + t2.a});
    }

    void query(int id, int l, int r, int pos, int val, vector<Node> &ST)
    {
        if(pos < l || pos > r) return;
        if(l == r)
        {
            ST[id].ab = max(0, val);
            return;
        }
        int mid = (l + r) >> 1;
        query(id*2 + 1, l, mid, pos, val, ST);
        query(id*2 + 2, mid + 1, r, pos, val, ST);
        Node t1 = ST[id*2 + 1], t2 = ST[id*2 + 2];
        ST[id].ab = max({t1.a + t2.ab, t1.a + t2.b, t1.ab + t2.b});
        ST[id].a = max({t1.a + t2.a, t1.a + t2.c, t1.ab + t2.c});
        ST[id].b = max({t1.b + t2.b, t1.c + t2.b, t1.c + t2.ab});
        ST[id].c = max({t1.b + t2.c, t1.c + t2.c, t1.c + t2.a});
    }

    int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<Node> ST(n * 4);
        build(0, 0, n - 1, ST, nums);
        long long ans = 0;
        for(int i = 0; i < queries.size(); i++)
        {
            query(0, 0, n - 1, queries[i][0], queries[i][1], ST);
            ans += max({ST[0].a, ST[0].b, ST[0].ab, ST[0].c});
            ans %= (1000000007);
        }
        return ans;
    }
};