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
        int n = 100000;
        st.resize(4 * n, 0);
        sort(envelopes.begin(), envelopes.end());
        int ans = 1, i = 0;
        while(i < envelopes.size()){
            vector<vector<int>> vt;
            int j = envelopes[i][0];
            while(i < envelopes.size() && envelopes[i][0] == j){
                vt.push_back({envelopes[i][1], get(0, 0, n - 1, 0, envelopes[i][1] - 1) + 1});
                i++;
            }
            for(j = 0; j < vt.size(); j++){
                ans = max(ans, vt[j][1]);
                update(0, 0, n - 1, vt[j][0], vt[j][1]);
            }
        }
        return ans;
    }
};