class Solution {
public:
    int maximumSwap(int num) {
        vector<int> vt;
        while(num)
        {
            vt.push_back(num % 10);
            num /= 10;
        }
        for(int j = vt.size() - 1; j >= 0; j--)
        {
            int res = j;
            for(int i = j - 1; i >= 0; i--)
            {
                
                if(vt[i] >= vt[res])
                {
                    res = i;
                }
            }
            if(vt[res] != vt[j])
            {
                swap(vt[res], vt[j]);
                break;
            }
        }
        int ans = 0, res = 1;
        for(int i = 0; i < vt.size(); i++)
        {
            ans += vt[i] * res;
            res *= 10;
        }
        return ans;
    }
};