class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        for(int i = 0; i < logs.size(); i++)
        {
            if(logs[i][0] == '.')
            {
                if(logs[i].size() == 3) ans = max(0, ans - 1);
            }else
            {
                ans++;
            }
        }
        return ans;
    }
};