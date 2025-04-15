class Solution {
public:

    struct SegmentTree{
        vector<int> ST;

        SegmentTree(int n){
            ST.resize(4 * n, 0);
        }

        void update(int id, int l, int r, int pos){
            if(pos < l || pos > r) return;

            if(l == r){
                ST[id] = 1;
                return;
            }

            int mid = (l + r)/2;

            update(id * 2 + 1, l, mid, pos);
            update(id * 2 + 2, mid + 1, r, pos);

            ST[id] = ST[id * 2 + 1] + ST[id * 2 + 2];
        }

        int get(int id, int l, int r, int u, int v){
            if(u > r || v < l) return 0;
            if(u <= l && r <= v) return ST[id];
            int mid = (l + r)/2;
            return get(id * 2 + 1, l, mid, u, v) + get(id * 2 + 2, mid + 1, r, u, v);
        }

    };

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        SegmentTree s1(n), s2(n);
        vector<long long> pre(n), suf(n), mp(n);
        
        for(int i = 0; i < n; i++){
            mp[nums2[i]] = i;
        }

        for(int i = 0; i < n; i++){
            pre[i] = s1.get(0, 0, n - 1, 0, mp[nums1[i]]);
            s1.update(0, 0, n - 1, mp[nums1[i]]);
        }

        for(int i = n - 1; i >= 0; i--){
            suf[i] = s2.get(0, 0, n - 1, mp[nums1[i]], n - 1);
            s2.update(0, 0, n - 1, mp[nums1[i]]);
        }

        long long ans = 0;

        for(int i = 0; i < n; i++){
            ans += suf[i] * pre[i];
        }

        return ans;       
    }
};