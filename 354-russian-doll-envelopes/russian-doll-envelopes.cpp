class Solution {
public:
    vector<int> st;

    void update(int id, int l, int r, int pos, int val){
        if(r < pos || l > pos) return;
        if(l == r){
            st[id] = max(st[id], val);
            return;
        }
        int mid = (l + r)/2;
        update(id * 2 + 1, l, mid, pos, val);
        update(id * 2 + 2, mid + 1, r, pos, val);
        st[id] = max(st[id*2 + 1], st[id*2 + 2]);
    }

    int get(int id, int l, int r, int u, int v){
        if(r < u || l > v) return 0;
        if(u <= l && r <= v) return st[id];
        int mid = (l + r)/2;
        return max(get(id*2 + 1, l, mid, u, v), get(id*2 + 2, mid + 1, r, u, v));
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = 0;
        for(auto x: envelopes) n = max(n, x[1]);
        st.resize(4 * n, 0);
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        int ans = 1;
        for(int i = 0; i < envelopes.size(); i++){
            int x = get(0, 0, n - 1, 0, envelopes[i][1] - 1);
            ans = max(x + 1, ans);
            update(0, 0, n - 1, envelopes[i][1], x + 1);
        }
        return ans;
    }
};