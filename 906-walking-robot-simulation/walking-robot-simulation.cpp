class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        set<pair<int, int>> mp;
        for(auto x: obstacles)
        {
            mp.insert({x[0], x[1]});
        }
        int x = 0, y = 0, res = 1, ans = 0;
        for(int i = 0; i < commands.size(); i++)
        {
            if(commands[i] < 0)
            {
                if(commands[i] == -1) res++;
                else res--;
                res = (res + 4)%4;
            }else
            {
                if(!res)
                {
                    for(int j = 1; j <= commands[i]; j++)
                    {
                        if(mp.find({x - 1, y}) == mp.end()) x--;
                        else break;
                        ans = max(ans, x*x + y*y);
                    }
                }else if(res == 2)
                {
                    for(int j = 1; j <= commands[i]; j++)
                    {
                        if(mp.find({x + 1, y}) == mp.end()) x++;
                        else break;
                        ans = max(ans, x*x + y*y);
                    }
                }else if(res == 1)
                {
                    for(int j = 1; j <= commands[i]; j++)
                    {
                        if(mp.find({x, y + 1}) == mp.end()) y++;
                        else break;
                        ans = max(ans, x*x + y*y);
                    }
                }else
                {
                    for(int j = 1; j <= commands[i]; j++)
                    {
                        if(mp.find({x, y - 1}) == mp.end()) y--;
                        else break;
                        ans = max(ans, x*x + y*y);
                    }
                }
            }

        }
        return ans;
        
    }
};