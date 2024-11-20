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
        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });
        vector<pair<int, int>> vt;
        for(int i = 0; i < envelopes.size(); i++){
            vt.push_back({envelopes[i][1], i});
        }
        sort(vt.begin(), vt.end());
        int n = 1;
        envelopes[vt[0].second][1] = 0;
        for(int i = 1; i < vt.size(); i++){
            if(vt[i].first > vt[i - 1].first) envelopes[vt[i].second][1] = n++;
            else envelopes[vt[i].second] = envelopes[vt[i - 1].second];
        }
        st.resize(4 * n, 0);
        int ans = 1;
        for(int i = 0; i < envelopes.size(); i++){
            int x = get(0, 0, n - 1, 0, envelopes[i][1] - 1);
            ans = max(x + 1, ans);
            update(0, 0, n - 1, envelopes[i][1], x + 1);
        }
        return ans;
    }
};