class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> vt(101);
        for(int i = 0; i < heights.size(); i++)
        {
            vt[heights[i]]++;
        }
        int i = 1, j = 0, ans = 0;
        while(j < heights.size())
        {
            if(vt[i] != 0)
            {
                if(heights[j] != i) ans++;
                j++;
                vt[i]--;                
            }else i++;
        }
        return ans;
    }
};