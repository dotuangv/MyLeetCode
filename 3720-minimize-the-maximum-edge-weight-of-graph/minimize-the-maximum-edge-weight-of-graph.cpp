class Solution {
public:
    bool isGood(vector<vector<pair<int, int>>> &parent, vector<int> cnt, int x, int n, int threshold){
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        int res = 0;
        while(!q.empty()){
            int y = q.front();
            q.pop();
            if(visited[y]){
                cnt[y]--;
                continue;
            }
            visited[y] = true;
            for(auto [a, b]: parent[y]){
                if(b <= x) q.push(a);
                else {
                    cnt[a]--;
                    res++;
                }
            }
        }

        for(int i = 0; i < n; i++){
            if(!visited[i] || cnt[i] > threshold) return false;
        }
        return true;
    }

    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<pair<int, int>>> parent(n);
        vector<int> cnt(n);
        int Max = 0;
        for(int i = 0; i < edges.size(); i++){
            cnt[edges[i][0]]++;
            parent[edges[i][1]].push_back({edges[i][0], edges[i][2]});
            Max = max(Max, edges[i][2]);
        }
        int l = 1, r = Max;
        bool ok = false;
        while(r > l + 1){
            int mid = (l + r)/2;
            if(isGood(parent, cnt, mid, n, threshold)) r = mid;
            else l = mid;
        }
        if(isGood(parent, cnt, l, n, threshold)) return l;
        else if(isGood(parent, cnt, r, n, threshold)) return r;
        return -1;
        
    }
};