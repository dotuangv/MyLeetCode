class Solution {
public:
    bool isGood(vector<int> &position, int m, int mid)
    {
        int res = 1, tmp = position[0];
        for(int i = 1; i < position.size(); i++)
        {
            if(position[i] - tmp >= mid)
            {
                res++;
                tmp = position[i];
            }
        }
        return res >= m;
    }
    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int l = 1, r = *max_element(position.begin(), position.end());
        while(r > l + 1)
        {
            int mid = (l + r)/2;
            if(isGood(position, m, mid)) l = mid;
            else r = mid;
        }
        if(isGood(position, m, r)) return r;
        return l;
    }
};