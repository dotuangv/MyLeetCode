class Solution {
public:
    
    vector<long long> dijkstra(int start, vector<vector<pair<long long, long long>>> &Child) {
    vector<long long> distances(27, 1e18);
    priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>> pq;

    distances[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int current_node = pq.top().second;
        int current_distance = pq.top().first;
        pq.pop();

        if (current_distance > distances[current_node]) {
            continue;
        }

        for (const auto& neighbor : Child[current_node]) {
            int next_node = neighbor.first;
            int weight = neighbor.second;
            int new_distance = current_distance + weight;

            if (new_distance < distances[next_node]) {
                distances[next_node] = new_distance;
                pq.push({new_distance, next_node});
            }
        }
    }

    return distances;
}
    
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        int n = original.size();
        vector<int> ori(n), ch(n);
        for(int i = 0; i < n; i++)
        {
            ori[i] = original[i] - 'a';
            ch[i] = changed[i] - 'a';
        }
        int m = source.size();
        vector<int> sou(m), tar(m);
        for(int i = 0; i < m; i++)
        {
            sou[i] = source[i] - 'a';
            tar[i] = target[i] - 'a';
        }
        vector<vector<pair<long long, long long>>> Child(26);
        for(int i = 0; i < n; i++)
        {
            Child[ori[i]].push_back({ch[i], cost[i]});
        }
        long long ans = 0;
        vector<vector<long long>> dp(26);
        for(int i = 0; i <= 25; i++)
        {
            dp[i] = dijkstra(i, Child);
        }
        for(int i = 0; i < m; i++)
        {
            if(sou[i] != tar[i])
            {
                if(dp[sou[i]][tar[i]] != 1e18)
                {
                    ans += dp[sou[i]][tar[i]];
                }else return -1; 
            }
        }
        
        return ans;
    }
};