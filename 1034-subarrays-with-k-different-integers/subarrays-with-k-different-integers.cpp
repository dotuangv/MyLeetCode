class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        unordered_map<int, int> mp, check;
        queue<pair<int, int>> pq;
        int cnt = 0, l = 0, r = 0, ans = 0;
        while(r < nums.size())
        {
            if(mp[nums[r]] == 0)
            {
                if(cnt == k)
                {
                    while(l < r)
                    {
                        mp[nums[l]]--;
                        if(mp[nums[l]] == 0)
                        {
                            cnt--;
                            l++;
                            break;
                        }else l++;
                    }
                }else
                {
                    mp[nums[r]]++;
                    cnt++;
                    pq.push({r, nums[r]});
                    check[nums[r]] = r;
                    if(cnt == k)
                    {
                        while(1)
                        {
                            if(mp[pq.front().second] == 0 || pq.front().first != check[pq.front().second])
                            {
                                pq.pop();
                            }else break;
                        }
                        ans += pq.front().first - l + 1;
                    }
                    r++;
                }
            }else
            {
                mp[nums[r]]++;
                check[nums[r]] = r;
                pq.push({r, nums[r]});
                if(cnt == k)
                {
                    while(1)
                    {
                        if(mp[pq.front().second] == 0 || pq.front().first != check[pq.front().second])
                        {
                            pq.pop();
                        }else break;
                    }
                    ans += pq.front().first - l + 1;
                }
                r++;
            }
        }
        return ans;
    }
};