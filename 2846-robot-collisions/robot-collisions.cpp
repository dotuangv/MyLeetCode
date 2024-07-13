int _ = [](){ std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr); return 0; }();
class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        vector<pair<int, int>> pa;
        for(int i = 0; i < positions.size(); i++)
        {
            pa.push_back({positions[i], i});
        }
        sort(pa.begin(), pa.end());
        stack<int> st;
        vector<int> ans;
        for(int i = 0; i < pa.size(); i++)
        {
            if(directions[pa[i].second] == 'R') st.push(pa[i].second);
            else
            {
                if(st.empty()) ans.push_back(pa[i].second);
                else
                {
                    while(!st.empty())
                    {
                        int t = st.top();
                        st.pop();
                        if(healths[t] > healths[pa[i].second])
                        {
                            healths[t]--;
                            st.push(t);
                            healths[pa[i].second] = -1;
                            break;
                        }else if(healths[t] < healths[pa[i].second])
                        {
                            healths[pa[i].second]--;
                        }else
                        {
                            healths[pa[i].second] = -1;
                            break;
                        }
                    }
                    if(healths[pa[i].second] != -1) ans.push_back(pa[i].second);
                }
            }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i < ans.size(); i++)
        {
            ans[i] = healths[ans[i]];
        }
        return ans;
    }
};