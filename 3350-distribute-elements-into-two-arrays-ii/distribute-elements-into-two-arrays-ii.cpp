class Solution {
public:
    void update(int id, int l, int r, int pos, vector<int> &ST)
    {
        if(l > pos || r < pos) return;
        if(l == r)
        {
            ST[id]++;
            return;
        }
        int mid = (l + r)/2;
        update(id*2 + 1, l, mid, pos, ST);
        update(id*2 + 2, mid + 1, r, pos, ST);
        ST[id] = ST[id*2 + 1] + ST[id*2 + 2];
    }
    
    int get(int id, int l, int r, int u, int v, vector<int> &ST)
    {
        if(l > v || r < u) return 0;
        if(l >= u && r <= v)
        {
            return ST[id];
        }
        int mid = (l + r)/2;
        int t1 = get(id*2 + 1, l, mid, u, v, ST);
        int t2 = get(id*2 + 2, mid + 1, r, u, v, ST);
        return t1 + t2;
    }
    
    vector<int> resultArray(vector<int>& nums) {
        set<int> se;
        map<int, int> mp;
        for(auto x: nums) se.insert(x);
        int i = 0;
        for(auto x: se)
        {
            mp[x] = i;
            i++;
        }
        int n = se.size();
        vector<int> ST1(4*n), ST2(4*n);
        update(0, 0, n - 1, mp[nums[0]], ST1);
        update(0, 0, n - 1, mp[nums[1]], ST2);
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for(int i = 2; i < nums.size(); i++)
        {
            int t1 = get(0, 0, n - 1, mp[nums[i]] + 1, n - 1, ST1);
            int t2 = get(0, 0, n - 1, mp[nums[i]] + 1, n - 1, ST2);
            if(t1 > t2)
            {
                arr1.push_back(nums[i]);
                update(0, 0, n - 1, mp[nums[i]], ST1);
            }else if(t1 < t2)
            {
                arr2.push_back(nums[i]);
                update(0, 0, n - 1, mp[nums[i]], ST2);
            }else
            {
                if(arr1.size() <= arr2.size())
                {
                    arr1.push_back(nums[i]);
                    update(0, 0, n - 1, mp[nums[i]], ST1);
                }else
                {
                    arr2.push_back(nums[i]);
                    update(0, 0, n - 1, mp[nums[i]], ST2);
                }
            }
        }
        for(int i = 0; i < arr2.size(); i++)
        {
            arr1.push_back(arr2[i]);
        }
        return arr1;
    }
};