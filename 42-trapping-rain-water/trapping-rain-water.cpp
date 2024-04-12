class Solution {
public:
    int trap(vector<int>& height) {
         ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int l = 0, r = 1, ans = 0, sum = height[0];
        while(r < height.size())
        {
            sum += height[r];
            if(height[r] >= height[l])
            {
                ans += height[l] * (r - l) - sum + height[r];
                sum = height[r];
                l = r;
            }
            r++;
        }
        sum = height[height.size() - 1];
        int l1 = height.size() - 2;
        r = height.size() - 1;
        while(l1 >= l)
        {
             sum += height[l1];
            if(height[l1] >= height[r])
            {
                ans += height[r] * (r - l1) - sum + height[l1];
                sum = height[l1];
                r = l1;
            }
            l1--;
        }
        return ans;
    }
};