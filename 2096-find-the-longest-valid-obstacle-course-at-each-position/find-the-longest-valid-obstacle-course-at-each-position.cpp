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

    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = *max_element(obstacles.begin(), obstacles.end()) + 1;
        vector<int> ans(obstacles.size());
        st.resize(4*n);
        for(int i = 0; i < obstacles.size(); i++){
            int res = get(0, 0, n - 1, 0, obstacles[i]) + 1;
            ans[i] = res; 
            update(0, 0, n - 1, obstacles[i], res);
        }
        return ans;
    }
};