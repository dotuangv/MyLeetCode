int speedUp = []{std::ios::sync_with_stdio(0); std::cin.tie(0); return 0; }();
struct CustomCompare {
    bool operator()(pair<long long, int> &a, pair<long long, int> &b) {
        if(a.first > b.first)
        {
            return true;
        }else if(a.first == b.first)
        {
            return a.second > b.second;
        }
        return false;
    }
};
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, CustomCompare> pq;
        priority_queue<int, vector<int>, greater<int>> p;
        sort(meetings.begin(), meetings.end());
        vector<int> ans(n);
        for(int i = 0; i < n; i++)
        {
            p.push(i);
        }
        for(int i = 0; i < meetings.size(); i++)
        {
            if(pq.empty())
            {
                pq.push({meetings[i][1], p.top()});
                ans[p.top()]++;
                p.pop();
            }else
            {
                while(!pq.empty() && pq.top().first <= meetings[i][0])
                {
                    p.push(pq.top().second);
                    pq.pop();
                }
                if(!p.empty())
                {
                    ans[p.top()]++;
                    pq.push({meetings[i][1], p.top()});
                    p.pop();
                }else
                {
                    ans[pq.top().second]++;
                    pq.push({pq.top().first - meetings[i][0] + meetings[i][1], pq.top().second});
                    pq.pop();
                }
            }
        }
        int index = 0;
        for(int i = 0; i < n; i++)
        {
            // cout << ans[i] << " ";
            if(ans[i] > ans[index]) index = i;
        }
        return index;

        
    }
};