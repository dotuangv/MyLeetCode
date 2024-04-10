class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        vector<int> ans(n);
        vector<bool> check(n);
        queue<int> pre, pos;
        sort(deck.begin(), deck.end());
        
        for(int i = 0; i < n; i++)
        {
            pre.push(i);
            pos.push(n - i - 1);
        }
        int i = 0, cnt = 2;
        for(int res = 0; res < n; res++)
        {
            if(res == n - 1)
            {
                ans[pre.front()] = deck[res];
                break;
            }
            check[i] = true;
            ans[i] = deck[res];
            while(!pre.empty() && check[pre.front()]) pre.pop();
            while(!pos.empty() && check[pos.front()]) pos.pop();
            if(i + cnt < n)
            {
                i += cnt;
            }else
            {
                if(i < pos.front())
                {
                    if(!pre.empty()) i = pre.front();
                    cnt *= 2;
                }else
                {
                    if(!pre.empty()) i = pre.front() + cnt;
                    cnt *= 2;
                }
            }
        }
        return ans;
    }
};